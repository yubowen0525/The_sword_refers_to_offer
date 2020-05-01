# C++11随机数生成
     default_random_engine：随机非负数（不建议单独使用）；
    
     uniform_int_distribution：指定范围的随机非负数；
    
     uniform_real_distribution：指定范围的随机实数；
    
     bernoulli_distribution：指定概率的随机布尔值。


- `default_random_engine` 是一个随机数引擎类。它定义的调用运算符返回一个随机的 unsigned 类型的值。
```c++
#include <iostream>
#include <random>
using namespace std;
 
int main( ){
    default_random_engine e;
    for(int i=0; i<10; ++i)
        cout<<e( )<<endl;
    return 0;
}
```

- `uniform_int_distribution`是一个随机数分布类，也是个模板类，模板参数为生成随机数的类型（不过只能是 int、unsigned、short、unsigned short、long、unsigned long、long long、unsigned long long 中的一种）。它的构造函数接受两个值，表示随机数的分布范围（闭区间）。
```c++
#include <iostream>
#include <random>
using namespace std;
 
int main( ){
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 9);
    for(int i=0; i<10; ++i)
        cout<<u(e)<<endl;
    return 0;
}
```
- `uniform_real_distribution` 是一个随机数分布类，它也是模板类，参数表示随机数类型（可选类型为 float、double、long double）。构造函数也需要最大值和最小值作为参数。

- `bernoulli_distribution` 是一个分布类，但它不是模板类。它的构造函数只有一个参数，表示该类返回 true 的概率，该参数默认为 0.5 ，即返回 true 和 false 的概率相等。
```c++
#include <iostream>
#include <random>
using namespace std;
 
int main( ){
    default_random_engine e;
    bernoulli_distribution u;
    for(int i=0; i<10; ++i)
        cout<<u(e)<<endl;
    return 0;
}
```


- normal_distribution<> n(4, 1.5); //正态分布，大部分生成的随机数落在0-8之间 