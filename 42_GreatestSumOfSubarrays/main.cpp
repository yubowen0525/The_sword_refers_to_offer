#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /////////////////////////贪心
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        int pre_Sum = 0;
        int Max_Sum = array[0];
        for (int i = 0; i < array.size(); ++i) {
            pre_Sum = pre_Sum + array[i];
            Max_Sum = max(pre_Sum,Max_Sum);

            if(pre_Sum < 0)
            {
                pre_Sum = 0;
            }
        }

        return Max_Sum;
    }
    /////////////////////////动态规划
    int FindGreatestSumOfSubArray2(vector<int> array) {
        if(array.empty())
            return 0;
        int pre_Sum[array.size()];
        pre_Sum[0] = array[0];
        for (int i = 1; i < array.size(); ++i) {
            int sum = pre_Sum[i - 1] + array[i];
            if(sum < 0)
            {
                pre_Sum[i] = array[i];
            } else
                pre_Sum[i] = sum;
        }

        int Max = pre_Sum[0];
        for (int i = 0; i < sizeof(pre_Sum)/ sizeof(int); ++i) {
            Max = max(Max,pre_Sum[i]);
        }

        return Max;
    }
};

int main()
{

    Solution solution;
//    for (int i = 1; i < 10; ++i) {
//        solution.Insert(i);
//    }

//    cout<<solution.FindGreatestSumOfSubArray({6,-3,-2,7,-15,1,2,2})<<endl;
    cout<<solution.FindGreatestSumOfSubArray({-1,-2,-3,-4,-5,-6,-7,-8})<<endl;
    cout<<solution.FindGreatestSumOfSubArray({6,-3,-2,7,-15,1,2,2})<<endl;
}