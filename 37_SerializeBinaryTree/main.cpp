#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x,struct TreeNode *left = nullptr,struct TreeNode *right = nullptr) :
            val(x), left(left), right(right) {
    }
};

class Solution {
public:
    char* Serialize(TreeNode *root) {
        if(root == nullptr)
        {
            return nullptr;
        }

//        int* str = new int[1024];

//        memset(str,'\0',1024);
        string str;
        int index = 0;
        Serialize_(root,str);
        str.erase(str.length()-1);
        const char* str2 = str.c_str();
        char * str3 = new char[str.length()+1];
        strcpy(str3,str2);
        return str3;
    }

    void Serialize_(TreeNode* root,string& str)
    {
        if(root == nullptr)
        {
            str += '#';
            str += ',';
            return;
        }
        str += to_string(root->val);
        str += ',';
        Serialize_(root->left,str);
        Serialize_(root->right,str);

    }

    TreeNode* Deserialize(char *str) {
        if(str == nullptr)
            return nullptr;
        return Deserialize_(str);
    }

    TreeNode* Deserialize_(char *& str)
    {
        //此时str处于指针级别
        if(*str == '#')
        {
            ++++str;
            return NULL;
        }

        int number = 0;
        while(*str != ',')
        {
            number = number*10 + ((*(str++)) - '0');
        }
        ++str;

        TreeNode* root = new TreeNode(number);
        root->left = Deserialize_(str);
        root->right = Deserialize_(str);

        return root;
    }
};

int main()
{

//    TreeNode*  p5 = new TreeNode(3);
//    TreeNode*  p4 = new TreeNode(1);
//
//    TreeNode*  p3 = new TreeNode(5);
//    TreeNode*  p2 = new TreeNode(2,p4,p5);
//
//    TreeNode*  p_root = new TreeNode(4, p2,p3);



    TreeNode*  p3 = new TreeNode(150);
    TreeNode*  p2 = new TreeNode(50);

    TreeNode*  p_root = new TreeNode(100, p2,p3);

    Solution solution;
    auto ans = solution.Serialize(p_root);
    cout<<ans<<endl;

    auto p = solution.Deserialize(ans);
    cout<<p<<endl;

}