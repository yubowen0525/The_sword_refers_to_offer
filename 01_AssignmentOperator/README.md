**题目**：为该类型添加赋值运算符函数。

```cpp
class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    //CMyString& operator = (const CMyString& str);

    void Print();
      
private:
    char* m_pData;
};
```
**解**：
写代码关注下面几点：
- 连续赋值问题-----返回要引用，*this
- 形参的类型声明是否是常量引用 （可减少一次拷贝）
- 是否释放实例自身的内存。防止内存泄露
- 判断是否传入的实参与当前的对象(*this)是否是同一个实例。如果是直接返回，如果不判断就释放内存会导致严重错误

```cpp
CMyString&  CMyString::operator=(const CMyString& str)
{
    //是否是一个实例,用地址判断
    if(this == &str)
        return *this;

    //拷贝赋值，释放自己的空间
    delete m_pData;
    m_pData = nullptr;
//    cout<<"sizeof(str.m_pData):"<<sizeof(str.m_pData)<<endl;
//    cout<<"strlen(str.m_pData):"<<strlen(str.m_pData)<<endl;

    m_pData = new char[(strlen(str.m_pData) + 1)];  //strlen()不计算结束符空间，+1是'\0'的空间
    strcpy(m_pData,str.m_pData);

    return *this;
}
```

**这里还有一个问题：异常安全性，如果在new的时候出现异常，但是已经delete掉自身，自身数据被破坏。利用先拷贝一个副本的方法解决**

```
CMyString&  CMyString::operator=(const CMyString& str)
{
    //创建一个作用域，利用析构函数
    if(this != &str)
    {
        CMyString strTemp(str); //首先利用了拷贝构造函数

        char * pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }   //利用析构函数，析构原来的m_pData

    return *this;
}
```