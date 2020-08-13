#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x,struct TreeNode *left = nullptr ,struct TreeNode *right = nullptr) :
			val(x), left(left), right(right) {
	}
};


class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;

        TreeNode* list = nullptr;
        Convert_(pRootOfTree,&list);

        //此时的List在列表的尾
        while(list->left != nullptr)
        {
            list = list->left;
        }

        return list;
    }

    void Convert_(TreeNode* pRootOfTree,TreeNode** List)
    {
        if(pRootOfTree == nullptr)
            return;
        auto Current = pRootOfTree;
        Convert_(pRootOfTree->left,List);

        Current->left = *List;
        if(*List != nullptr)
            (*List)->right = Current;

        *List = Current;

        Convert_(pRootOfTree->right,List);
    }
};

int main()
{

    TreeNode*  p5 = new TreeNode(3);
    TreeNode*  p4 = new TreeNode(1);

    TreeNode*  p3 = new TreeNode(5);
    TreeNode*  p2 = new TreeNode(2,p4,p5);

    TreeNode*  p_root = new TreeNode(4, p2,p3);

    Solution solution;
    auto ans = solution.Convert(p_root);
    while(ans != nullptr)
    {
        cout<<ans->val<<" "<<endl;
        ans = ans->right;
    }


}