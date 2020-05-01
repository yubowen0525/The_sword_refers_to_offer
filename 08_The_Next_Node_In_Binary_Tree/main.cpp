#include <iostream>
#include <vector>

using namespace std;
typedef struct TreeNode* TNode;
typedef char ElementType;
struct TreeNode
{
    explicit TreeNode(ElementType x) : val(x), left(NULL), right(NULL) ,next(NULL){}
    ElementType val;
    TNode left;
    TNode right;
    TNode next;
};

typedef vector<ElementType>::iterator Iter;

TreeNode* construct(Iter PreStart,Iter PreEnd,Iter InStart,Iter InEnd)
{
    //建立根节点
    ElementType value = *PreStart;
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
        auto p = construct(PreStart+1,New_PreEnd,InStart,RootIndex-1);
        root->left = p;
        p->next = root;
    }
    //什么情况下有右子树呢？
    // 方案1：由中序算出左子树的长度，如果说左子树的长度小于先序序列的长度就证明了右子树的存在
//    size_t Length = PreEnd - PreStart;
    // 方案2：直接由中序序列求出右子树长度
    if(InEnd - RootIndex > 0)
//    if(leftLength < Length)
    {
        auto p =construct(New_PreEnd+1,PreEnd,RootIndex+1,InEnd);

        root->right = p;

        p->next = root;
    }

    //注意这里递归的插入
    return root;
}



TreeNode* reConstructBinaryTree(vector<ElementType>& pre,vector<ElementType>& vin) {
    if(pre.empty() || vin.empty() || pre.size() != vin.size())
        return nullptr;
    return construct(pre.begin(),pre.end() - 1,vin.begin(),vin.end() - 1);
}

//构造一颗二叉树
TreeNode* construct_tree()
{
    vector<ElementType> preorder;
    vector<ElementType> inorder;
    int n ;
    ElementType value;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>value;
        preorder.push_back(value);
    }

    for (int i = 0; i < n; ++i) {
        cin>>value;
        inorder.push_back(value);
    }

    return reConstructBinaryTree(preorder,inorder);
}

//选择一个节点，输出中序的下一个节点
TreeNode* GetNext(TreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;

    //情况1：有右节点
    if(pNode->right != nullptr)
    {
        TreeNode* pRight = pNode->right;
        while(pRight->left != nullptr)
            pRight = pRight->left;
        return pRight;
    } else  //无右节点
    {
        //是父亲节点的左节点
        if(pNode->next != nullptr && pNode->next->left == pNode)
        {
            return pNode->next;
        }
        else if(pNode->next != nullptr)
        {
            TreeNode* parent = pNode->next;
            TreeNode* p = pNode;
            while(parent->left != p)
            {
                if(parent->next != nullptr)
                    parent = parent->next;
                else    //没有父节点了
                    return nullptr;
                p = p->next;
            }
            //此时parent就是拥有父节点的左子节点的父亲
            return parent;
        }
    }
    return nullptr;
}



int main(){
    TNode root = construct_tree();
    auto test = root->right;
    TNode ans = GetNext(test);
    cout<<"节点:"<<test->val<<"中序的下一个节点:"<<ans->val<<endl;
}