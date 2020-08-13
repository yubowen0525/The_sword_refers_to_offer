#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int Sum = 0;
        for (int i = 1; i <= n; ++i) {
            Sum += NumberOf1(i);
        }
        return Sum;
    }

    int NumberOf1(int n)
    {
        int times_of_1 = 0;
        while(n)
        {
            n % 10 == 1 ? ++times_of_1 : 0;
            n /= 10;
        }
        return times_of_1;
    }

};
int main()
{

    Solution solution;
//    for (int i = 1; i < 10; ++i) {
//        solution.Insert(i);
//    }

//    cout<<solution.FindGreatestSumOfSubArray({6,-3,-2,7,-15,1,2,2})<<endl;
    cout<<solution.NumberOf1Between1AndN_Solution(10)<<endl;

}