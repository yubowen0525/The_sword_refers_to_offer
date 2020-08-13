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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(root == nullptr)
            return vector<int>();
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto p_tree = q.front();
            q.pop();

            ans.emplace_back(p_tree->val);

            if(p_tree->left != nullptr)
                q.push(p_tree->left);
            if(p_tree->right != nullptr)
                q.push(p_tree->right);
        }

        return ans;
    }

    void PrintFromTopToBottomInLines(TreeNode* root) {
        if(root == nullptr)
            return;

        queue<TreeNode*> q;
        int Num_level = 1;
        int Num_NextLine = 0;
        q.push(root);
        while(!q.empty())
        {
            auto p_tree = q.front();
            q.pop();

            cout<<p_tree->val<<" ";

            if(p_tree->left != nullptr)
            {
                q.push(p_tree->left);
                ++Num_NextLine;
            }
            if(p_tree->right != nullptr)
            {
                q.push(p_tree->right);
                ++Num_NextLine;
            }

            --Num_level;
            if(Num_level == 0)
            {
                cout<<endl;
                Num_level = Num_NextLine;
                Num_NextLine = 0;
            }

        }
    }


    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return vector<vector<int> >();
        vector<vector<int> > ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        int level = 1;
        int Next_level = 0;
        bool flag = false;
        s2.push(pRoot);
        vector<int> Rows;
        TreeNode* p_tree = nullptr;
        while(!s1.empty() || !s2.empty())
        {
            if(flag) {
                p_tree = s1.top();
                s1.pop();
            } else
            {
                p_tree = s2.top();
                s2.pop();
            }



            //打印加入元素
            Rows.emplace_back(p_tree->val);

            if(!flag)
            {
                if(p_tree->left != nullptr)
                {
                    s1.push(p_tree->left);
                    ++Next_level;
                }
                if(p_tree->right != nullptr)
                {
                    s1.push(p_tree->right);
                    ++Next_level;
                }
            } else
            {
                if(p_tree->right != nullptr)
                {
                    s2.push(p_tree->right);
                    ++Next_level;
                }
                if(p_tree->left != nullptr)
                {
                    s2.push(p_tree->left);
                    ++Next_level;
                }
            }

            --level;
            if(level == 0)
            {
                flag = !flag;
                level = Next_level;
                Next_level = 0;
                ans.push_back(Rows);
                Rows.clear();
            }

        }

        return ans;
    }
};

int main()
{
    TreeNode* p7 = new TreeNode(7);
    TreeNode*  p6 = new TreeNode(6, nullptr);

    TreeNode*  p5 = new TreeNode(5);
    TreeNode*  p4 = new TreeNode(4);

    TreeNode*  p3 = new TreeNode(3,p6,p7);
    TreeNode*  p2 = new TreeNode(2,p4,p5);

    TreeNode*  p_root = new TreeNode(1, p2,p3);

    Solution solution;

    ///////////////////////////////题目1
//    auto v = solution.PrintFromTopToBottom(p_root);
//    for(auto num : v)
//        cout<<num<<" ";
//    cout<<endl;

    //////////////////////////////题目2
//    solution.PrintFromTopToBottomInLines(p_root);

    /////////////////////////////题目3
    auto v_v = solution.Print(p_root);
    for(auto v : v_v)
    {
        for(auto num : v)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
}