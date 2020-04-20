#include <iostream>
#include <vector>

using namespace std;
typedef struct TreeNode* TNode;
struct TreeNode
{
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    int val;
    TNode left;
    TNode right;
};

typedef vector<int>::iterator Iter;

TreeNode* construct(Iter PreStart,Iter PreEnd,Iter InStart,Iter InEnd)
{
    //建立根节点
    int value = *PreStart;
    TNode root = new TreeNode(value);

    //此时锁定到一个节点，先序的左边界，与有边界相等那么值也应是相等的，直接返回
    if(PreStart == PreEnd)
    {
        if(*PreStart == *PreEnd)
            return root;
        else
            throw logic_error("invaild input");
    }


    //中序查找根节点的索引，中序的左边界到根节点的长度 = 左子树的长度
    Iter RootIndex = InStart;
    while(RootIndex != InEnd && (*RootIndex) != value)
        ++RootIndex;

    //如果没有找在中序找到根节点，输入是错误的
    if(RootIndex == InEnd && *RootIndex != value)
        throw std::logic_error("Invail input");

    //找到，由中序序列，计算左子树的长度
    size_t leftLength = RootIndex - InStart;
    //在先序中找到左子树的分界点
    Iter New_PreEnd = PreStart + (RootIndex - InStart);
    //什么情况有左子树？
    if(leftLength > 0)
    {
        root->left = construct(PreStart+1,New_PreEnd,InStart,RootIndex-1);
    }
    //什么情况下有右子树呢？
    // 方案1：由中序算出左子树的长度，如果说左子树的长度小于先序序列的长度就证明了右子树的存在
//    size_t Length = PreEnd - PreStart;
    // 方案2：直接由中序序列求出右子树长度
    if(InEnd - RootIndex > 0)
//    if(leftLength < Length)
    {
        root->right = construct(New_PreEnd+1,PreEnd,RootIndex+1,InEnd);
    }

    //注意这里递归的插入
    return root;


}



TreeNode* reConstructBinaryTree(vector<int>& pre,vector<int>& vin) {
    if(pre.empty() || vin.empty() || pre.size() != vin.size())
        return nullptr;
    return construct(pre.begin(),pre.end() - 1,vin.begin(),vin.end() - 1);
}

int main(){
    vector<int> preorder;
    vector<int> inorder;
    int n,value;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>value;
        preorder.push_back(value);
    }

    for (int i = 0; i < n; ++i) {
        cin>>value;
        inorder.push_back(value);
    }

    TNode ROOT = reConstructBinaryTree(preorder,inorder);

    cout<<ROOT<<endl;
    return 0;
}