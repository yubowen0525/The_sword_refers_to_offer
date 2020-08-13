#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    //任意第n位对应的数字
    int NumbersOfOneCentern(int n)
    {
        if(n < 0)
            return -1;

        if(n == 0)
            return 0;

        int digit = 1;
        int temp_digit = 0;
        while(true)
        {
            //计算属于几位
            int digits = CountOfDigits(digit);
            digits *= digit;
            if(n < digits)
                break;
            n -= digits;
            ++digit;
        }

        //
        return NumbersOfOne(n,digit);
    }
    int CountOfDigits(int digit)
    {
        if(digit == 1)
            return 10;
        int count = std::pow(10,digit-1);
        return 9 * count;
    }

    int NumbersOfOne(int n,int digit)
    {
        int left_boundry =  digit != 1 ? std::pow(10,digit - 1) : 0;
        int Ans = n / digit;
        Ans += left_boundry;
        int Reminder = n % digit;
        if(digit < Reminder)
        {
            cout<<"出错"<<endl;
            return 0;
        }

        for (int i = 1; i < digit - Reminder; ++i) {
            Ans /= 10;
        }

        return Ans % 10;
    }

};
int main()
{

    Solution solution;
//    cout<<solution.NumbersOfOneCentern(10)<<endl;
//    cout<<solution.NumbersOfOneCentern(11)<<endl;
//    for (int i = 190; i < 220; ++i) {
//        cout<<solution.NumbersOfOneCentern(i)<<endl;
//    }

    for (int i = 2890; i < 2990; ++i) {
        cout<<solution.NumbersOfOneCentern(i)<<endl;
    }

}