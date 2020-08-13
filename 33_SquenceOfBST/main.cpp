#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;



class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return VerifySquenceOfBST_(sequence,0,sequence.size()-1);
    }

    bool VerifySquenceOfBST_(vector<int>& sequence,int left,int right) {
        if(left > right)
            return false;

        // i 为右子树的第一个索引
        int i = left;
        for (; i < right; ++i) {
            if(sequence[i] > sequence[right])
                break;
        }

        // i ~ (right - 1) 应该大于 根节点
        for (int j = i + 1; j < right; ++j) {
            if(sequence[j] <= sequence[right])
                return false;
        }

        //左子树
        bool flag_left = true;
        if(left < i)
            flag_left = VerifySquenceOfBST_(sequence,left,i-1);

        //右子树
        bool flag_right = true;
        if(i < right)
            flag_right = VerifySquenceOfBST_(sequence,i,right - 1);

        return flag_left && flag_right;
    }
};

int main()
{


    Solution solution;
    cout<<solution.VerifySquenceOfBST({5,7,6,9,11,10,8})<<endl;
    cout<<solution.VerifySquenceOfBST({7,6,9,8})<<endl;
}