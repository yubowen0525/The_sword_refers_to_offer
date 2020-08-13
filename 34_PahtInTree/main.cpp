#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x,struct TreeNode * left = nullptr,struct TreeNode * right = nullptr) :
            val(x), left(left),right(right) {
    }
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr)
            return vector<vector<int>>();
        vector<int> Stack;
        vector<vector<int> > ans;
        FindPath_(root,ans,Stack,expectNumber);
        return ans;
    }

    void FindPath_(TreeNode* root,vector<vector<int>>& ans,vector<int> Stack,int expectNumber)
    {
        if(root == nullptr)
            return;

        expectNumber -= root->val;
        Stack.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && expectNumber == 0)
        {
            ans.push_back(Stack);
        }

        FindPath_(root->left,ans,Stack,expectNumber);
        FindPath_(root->right,ans,Stack,expectNumber);

        Stack.pop_back();
    }
};

int main()
{

    TreeNode*  p5 = new TreeNode(7);
    TreeNode*  p4 = new TreeNode(4);

    TreeNode*  p3 = new TreeNode(12);
    TreeNode*  p2 = new TreeNode(5,p4,p5);

    TreeNode*  p_root = new TreeNode(10, p2,p3);

    Solution solution;
    auto ans = solution.FindPath(p_root,22);
    for(auto v:ans)
    {
        for(auto num : v)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }

}