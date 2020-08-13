#include <iostream>
#include <vector>
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

void pre_print(TreeNode* root)
{
    if(root == nullptr)
        return;
    cout<<root->val<<" ";
    pre_print(root->left);
    pre_print(root->right);

}

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        bool flag = false;
        if(pRoot1->val == pRoot2->val)
            flag = Is_Subtree(pRoot1,pRoot2);
        if(!flag)
            flag = HasSubtree(pRoot1->left,pRoot2);
        if(!flag)
            flag = HasSubtree(pRoot1->right,pRoot2);
        return flag;
    }

    bool Is_Subtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //子结构节点为空
        if(pRoot2 == nullptr)
            return true;
        //子结构不空
        if(pRoot1 == nullptr)
            return false;

        //都不空
        if(pRoot1->val == pRoot2->val)
            return Is_Subtree(pRoot1->left,pRoot2->left) && Is_Subtree(pRoot1->right,pRoot2->right);
        else
            return false;
    }
};

int main()
{

    TreeNode* p7 = new TreeNode(7);
    TreeNode*  p6 = new TreeNode(4, nullptr);

    TreeNode*  p5 = new TreeNode(2, p6,p7);
    TreeNode*  p4 = new TreeNode(9);

    TreeNode*  p3 = new TreeNode(7);
    TreeNode*  p2 = new TreeNode(8,p4,p5);

    TreeNode*  p_root = new TreeNode(8, p2,p3);


    TreeNode*  d3 = new TreeNode(2);
    TreeNode*  d2 = new TreeNode(9);
    TreeNode*  d1 = new TreeNode(8, d2,d3);


//    p7->next = p3;

    Solution solution;
    auto test = solution.HasSubtree(p_root,d1);
    cout<<test<<endl;
    pre_print(d1);
    cout<<endl;



}