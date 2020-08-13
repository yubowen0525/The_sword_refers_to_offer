#include <iostream>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == nullptr || pattern == nullptr)
            return false;
        //递归
        return match_core(str,pattern);
    }

    bool match_core(char* str,char* pattern)
    {
        //字符结束标记 '0'  匹配
        if(*str == '\0' && *pattern == '\0')
            return true;
        //不匹配str还有，pattern结束
        if(*str != '\0' && *pattern == '\0')
            return false;

        //下一个数是*特殊处理
        //可以匹配0次，也可以匹配1次
        if(*(pattern + 1) == '*')
        {
            //匹配0次或者更多次
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
                return match_core(str+1,pattern)  //匹配更多次
                    || match_core(str+1,pattern+2)  //匹配1次
                    || match_core(str,pattern+2);       //匹配0次
            else  //不匹配，只能按0次来说
                return match_core(str,pattern+2);

        } else
        {
            //匹配后移动
            if(*str == *pattern || (*pattern == '.' && *str != '\0'))
                return match_core(str+1,pattern+1);
            else
                return false;
        }

    }



};


int main()
{
    Solution solution;
    cout<<solution.match("aaa","\"\",\".*\"")<<endl;

}