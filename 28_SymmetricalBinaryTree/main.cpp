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
    bool isSymmetrical(TreeNode* pRoot)
    {
        vector<int> s1;
        vector<int> s2;

        isSymmetrical1(pRoot,s1);
        isSymmetrical2(pRoot,s2);

        return s1 == s2;
    }

    void isSymmetrical1(TreeNode* pRoot1,vector<int>& v)
    {
        if(pRoot1 == nullptr)
        {
            v.push_back(INT32_MIN);
            return;
        }
        v.push_back(pRoot1->val);
        isSymmetrical1(pRoot1->left,v);
        isSymmetrical1(pRoot1->right,v);
    }

    void isSymmetrical2(TreeNode* pRoot1,vector<int>& v)
    {
        if(pRoot1 == nullptr)
        {
            v.push_back(INT32_MIN);
            return;
        }
        v.push_back(pRoot1->val);
        isSymmetrical2(pRoot1->right,v);
        isSymmetrical2(pRoot1->left,v);
    }
///////////////////////////////////////////////////////////////////////////////
    //不用容器得解法
    bool isSymmetrical_(TreeNode* pRoot)
    {
        vector<int> s1;
        vector<int> s2;

        isSymmetrical1(pRoot,s1);
        isSymmetrical2(pRoot,s2);

        return s1 == s2;
    }

    bool isSymmetrical_(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr && pRoot2 == nullptr)
            return true;
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        if(pRoot1->val != pRoot2->val)
            return false;

        //两者相等继续下探
        return isSymmetrical_(pRoot1->left,pRoot2->right) &&
                isSymmetrical_(pRoot1->right,pRoot2->left);

    }


};

int main()
{

    TreeNode* p7 = new TreeNode(0);
    TreeNode*  p6 = new TreeNode(7);

    TreeNode*  p5 = new TreeNode(7);
    TreeNode*  p4 = new TreeNode(5);

    TreeNode*  p3 = new TreeNode(6,p6,p7);
    TreeNode*  p2 = new TreeNode(6,p4,p5);

    TreeNode*  p_root = new TreeNode(8, p2,p3);

 


//    p7->next = p3;

    Solution solution;
    cout<<solution.isSymmetrical_(p_root)<<endl;
//    cout<<test<<endl;
//    pre_print(p_root);
//    cout<<endl;



}