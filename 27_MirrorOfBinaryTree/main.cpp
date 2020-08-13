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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr)
            return;
        if(pRoot->left != nullptr || pRoot->right != nullptr)
        {
            auto temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
        }
        if(pRoot->left) //减枝
            Mirror(pRoot->left);
        if(pRoot->right)    //减枝
            Mirror(pRoot->right);
    }
};

int main()
{

    TreeNode* p7 = new TreeNode(11);
    TreeNode*  p6 = new TreeNode(9);

    TreeNode*  p5 = new TreeNode(7);
    TreeNode*  p4 = new TreeNode(5);

    TreeNode*  p3 = new TreeNode(10,p6,p7);
    TreeNode*  p2 = new TreeNode(6,p4,p5);

    TreeNode*  p_root = new TreeNode(8, p2,p3);




//    p7->next = p3;

    Solution solution;
    solution.Mirror(p_root);
//    cout<<test<<endl;
    pre_print(p_root);
    cout<<endl;



}