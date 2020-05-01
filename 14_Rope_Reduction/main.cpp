#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    //动态规划
    int cutRope1(int number) {
        if(number < 2)
            return 0;
        if(number == 2)
            return 1;
        if(number == 3)
            return 2;

        vector<int> product(number);
        product = {0,1,2,3};

        int result = 0;
        int Max = 0;
        for (int i = 4; i <= number; ++i) {

            for (int j = 1; j < i; ++j) {
                result = product[j] * product[i - j];
                Max = max(Max,result);
            }
            product[i] = Max;
        }

        return Max;




    }

    //贪心
    int cutRope2(int number) {
        int result[3] = {1,2,4};
        if(number<2)
            return 0;
        if(number<5)
            return result[number-2];

        //n>=5的
        int result2=1;
        for (; number > 4; number -= 3) {
            result2 *= 3;
        }

        if(number == 4)
            result2 *= ----number;

        if(number == 0)
            return result2;

        result2*=number;

        return result2;
        
    }
};


int main(){
    Solution solution;
    cout<<solution.cutRope1(8)<<endl;


}