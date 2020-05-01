#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define ERROR -1  //分母为0
class Solution {
public:
    bool isEqual(double a, double b,double Accuracy)
    {
        return fabs(a - b) < Accuracy;
    }

    double Power(double base, int exponent) {

        if(exponent < 0)
        {
            if(isEqual(base,0.0,10e-6))
                return ERROR;

            return 1.0 / PowerCore(base,-exponent);
        }
        else if(exponent == 0)
            return 1.0;
        else
        {
            return PowerCore3(base,exponent);
        }


    }

    double PowerCore(double base, int exponent)
    {
        double result = 1.0;
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
        return result;
    }
    //快速幂
    double PowerCore2(double base, int exponent)
    {
        long double result = 1.0;
        for (; exponent > 1; exponent>>=1) {
            if(exponent & 0x1)
            {
                result *= base;
            }
            base *= base;
        }

        return result * base;
    }

    //快速幂取模防止溢出，默认取后三位
    long long PowerCore3(int base, int exponent,int mode=1000)
    {
        long long result = 1;
        for (; exponent > 1; exponent>>=1) {
            if(exponent & 0x1)
            {
                result = (result * base) % mode ;
            }
            base = (base * base) % mode ;
        }

        return (result * base) % mode;
    }

};

int main(){
    Solution solution;
    cout<<solution.Power(2,100)<<endl;
}