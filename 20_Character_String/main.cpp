#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == nullptr)
            return false;

        if(*string == '+' || *string == '-')
            ++string;
        bool flag = scannum(&string);


        if(*string == '.')
        {
            ++string;
            //保证233.的情况
            flag = scannum(&string) || flag;
        }

        if(*string == 'e' || *string == 'E')
        {
            ++string;
            if(*string == '+' || *string == '-')
                ++string;

            flag = scannum(&string);
        }

        return *string == '\0'? flag : false;

    }

    bool scannum(char** str)
    {
        char* before = *str;

        while(**str >= '0' && **str <= '9')
            ++(*str);

        //如果没有动那么返回false
        return *str > before;
    }





};


int main()
{
    Solution solution;
    cout<<solution.isNumeric("233.")<<endl;

}