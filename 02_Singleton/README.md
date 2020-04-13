# std::lock_guard
>1.std::lock_guard 在构造函数中进行加锁，析构函数中进行解锁。
>
>2.锁在多线程编程中，使用较多，因此c++11提供了lock_guard模板类；在实际编程中，我们也可以根据自己的场景编写resource_guard RAII类，避免忘掉释放资源。

# std::unique_lock
>类 unique_lock 是通用互斥包装器，允许`延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用`。
>
>unique_lock比lock_guard使用更加灵活，功能更加强大。
>
>使用unique_lock需要付出更多的时间、性能成本。


# std::move()
https://blog.csdn.net/p942005405/article/details/84644069

[toc]
# 题目：设计一个类，我们只能生成该类的一个实例

什么是单例：

单例 Singleton 是设计模式的一种，其特点是只提供**唯一**一个类的实例,具有全局变量的特点，在任何位置都可以通过接口获取到那个唯一实例;
具体运用场景如：
1. 设备管理器，系统中可能有多个设备，但是只有一个设备管理器，用于管理设备驱动;
2. 数据池，用来缓存数据的数据结构，需要在一处写，多处读取或者多处写，多处读取;

## 基础要点

- 全局只有一个实例：static 特性，同时禁止用户自己声明并定义实例（把构造函数设为 private）
- 线程安全
- 禁止赋值和拷贝用户通过接口获取实例：使用 static 类成员函数

## 方式1 有缺陷的懒汉式(Lazy-Initialization)


懒汉式(Lazy-Initialization)的方法是直到使用时才实例化对象，也就说直到调用get_instance() 方法的时候才 new 一个单例的对象。好处是如果被调用就不会占用内存。

```cpp
#include <iostream>
using namespace std;
// version1:
// with problems below:
// 1. thread is not safe
// 2. memory leak
class Singleton{
private:
    //构造函数
    Singleton(){
        cout<<"Singleton constructor called"<<endl;
    }
    //拷贝赋值函数
    Singleton(Singleton&) = delete;
    Singleton& operator=(Singleton&) = delete;
    //静态指针
    static Singleton* m_instance_ptr;
public:
    //实例
    static Singleton* get_instance()
    {
        if(m_instance_ptr == nullptr)
        {
            m_instance_ptr = new Singleton();
        }

        return m_instance_ptr;
    }

    void use() const { std::cout << "in use" << std::endl; }
};

Singleton* Singleton::m_instance_ptr = nullptr;


int main(){
    Singleton* instance = Singleton::get_instance();
    Singleton* instance_2 = Singleton::get_instance();
    return 0;
}
```

- **线程安全的问题**,当多线程获取单例时有可能引发竞态条件：第一个线程在if中判断 m_instance_ptr是空的，于是开始实例化单例;同时第2个线程也尝试获取单例，这个时候判断m_instance_ptr还是空的，于是也开始实例化单例;这样就会实例化出两个对象,这就是线程安全问题的由来; **解决办法:加锁**
- **内存泄漏**. 注意到类中只负责new出对象，却没有负责delete对象，因此只有构造函数被调用，析构函数却没有被调用;因此会导致内存泄漏。解决办法： **使用共享指针**;

## 方法2 ，增加锁，动态指针
```cpp
#include <memory>
#include <mutex>
// version 2:
// with problems below fixed:
// 1. thread is safe now
// 2. memory doesn't leak
class Singleton_safe{
public:
    typedef shared_ptr<Singleton_safe> Ptr;

    ~Singleton_safe(){
        cout<<"Singleton_safe destructor called"<<endl;
    }

    //拷贝赋值函数
    Singleton_safe(Singleton&) = delete;
    Singleton_safe& operator=(Singleton&) = delete;

    static Ptr get_instance()
    {
        if(m_instance_ptr == nullptr)
        {
            //加锁
            std::lock_guard<std::mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr)
                m_instance_ptr = shared_ptr<Singleton_safe>(new Singleton_safe);
        }

        return m_instance_ptr;
    }

private:
    Singleton_safe(){
        std::cout<<"Singleton_safe constructor called!"<<std::endl;
    }
    static Ptr m_instance_ptr;
    static std::mutex m_mutex;
};

Singleton_safe::Ptr Singleton_safe::m_instance_ptr = nullptr;
std::mutex Singleton_safe::m_mutex;
```

shared_ptr和mutex都是C++11的标准，以上这种方法的优点是

- 基于 shared_ptr, 用了C++比较倡导的 RAII思想，用对象管理资源,当 shared_ptr 析构的时候，new 出来的对象也会被 delete掉。以此避免内存泄漏。
- 加了锁，使用互斥量来达到线程安全。这里使用了两个 if判断语句的技术称为**双检锁**；好处是，只有判断指针为空的时候才加锁，避免每次调用 get_instance的方法都加锁，锁的开销毕竟还是有点大的。


**不足之处在于**： 使用智能指针会要求用户也得使用智能指针，非必要不应该提出这种约束; 使用锁也有开销; 同时代码量也增多了，实现上我们希望越简单越好。

## 方法三  最推荐的懒汉式单例(magic static )——局部静态变量

```cpp
#include <iostream>

class Singleton
{
public:
    ~Singleton(){
        std::cout<<"destructor called!"<<std::endl;
    }
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Singleton& get_instance(){
        static Singleton instance;
        return instance;

    }
private:
    Singleton(){
        std::cout<<"constructor called!"<<std::endl;
    }
};
```

这种方法又叫做 Meyers' SingletonMeyer's的单例， 是著名的写出《Effective C++》系列书籍的作者 Meyers 提出的。所用到的特性是在C++11标准中的Magic Static特性：

>If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization.
>**如果当变量在初始化的时候，并发同时进入声明语句，并发线程将会阻塞等待初始化结束**。

C++静态变量的生存期 是从声明到程序结束，这也是一种懒汉式。


**这是最推荐的一种单例实现方式**：

- 通过**局部静态变量的特性保证了线程安全** (C++11, GCC > 4.3, VS2015支持该特性); C++11标准说局部静态变量初始化具有安全性
- 不需要使用共享指针，代码简洁；
- 注意在使用的时候需要声明单例的引用 Single& 才能获取对象。


另外网上有人的实现返回指针而不是返回引用
```
static Singleton* get_instance()
{ static Singleton instance; return &instance; }
```

这样做并不好，理由主要是无法避免用户使用`delete instance`导致对象被提前销毁。还是建议大家使用返回引用的方式。