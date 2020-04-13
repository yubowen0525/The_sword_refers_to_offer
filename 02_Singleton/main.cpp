#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////
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
    ~Singleton(){
        cout<<"Singleton destructor called"<<endl;
    }
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

    //拷贝赋值函数
    Singleton(Singleton&) = delete;
    Singleton& operator=(Singleton&) = delete;
};

Singleton* Singleton::m_instance_ptr = nullptr;
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////
#include <iostream>

class Singleton_LocalStatic
{
public:
    ~Singleton_LocalStatic(){
        std::cout<<"Singleton_LocalStatic destructor called!"<<std::endl;
    }
    Singleton_LocalStatic(const Singleton_LocalStatic&)=delete;
    Singleton_LocalStatic& operator=(const Singleton_LocalStatic&)=delete;
    static Singleton_LocalStatic& get_instance(){
        static Singleton_LocalStatic instance;
        return instance;

    }
private:
    Singleton_LocalStatic(){
        std::cout<<"Singleton_LocalStatic constructor called!"<<std::endl;
    }
};

int main(){
    Singleton* instance = Singleton::get_instance();
    Singleton* instance_2 = Singleton::get_instance();
    Singleton_safe::Ptr instance3 = Singleton_safe::get_instance();
    Singleton_safe::Ptr instance4 = Singleton_safe::get_instance();

    Singleton_LocalStatic& instance5 = Singleton_LocalStatic::get_instance();
    Singleton_LocalStatic& instance6 = Singleton_LocalStatic::get_instance();
    return 0;
}