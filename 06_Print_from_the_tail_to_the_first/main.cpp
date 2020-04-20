#include <iostream>
#include <iterator>
#include <regex>
#include <string>
using namespace std;

typedef struct ListNode* List;

struct ListNode
{
    explicit ListNode(List p_next = nullptr,int value = 0)
        :p_Next(p_next),Value(value)
    {}

    int Value;
    List p_Next;
};

void AddToTail(List *head, int value)
{
    List New = new ListNode(nullptr,value);
    if(*head == nullptr)    //如果链表没有节点，那就赋值一个
        *head = New;
    else{
        //遍历链表
        List p = *head;
        while(p->p_Next != nullptr)
        {
            p = p->p_Next;
        }
        //p到达最后一个节点的位置,进行连接
        p->p_Next = New;
    }
}

//移除是value的节点
void RemoveNode(List* head,int value)
{
    //输入空指针，或第一个节点是空就返回
    if(head == nullptr || *head == nullptr)
        return;
    //删除的节点位置
    List delete_node = nullptr;
    List p = *head;

    //头节点就是
    if(p->Value == value)
    {
        delete_node = p;
       *head = p->p_Next;
    }
    else{
        //遍历链表
        while(p->p_Next != nullptr || p->p_Next->Value != value )
        {
            p = p->p_Next;
        }

        //节点在链表的中间
        if(p->p_Next != nullptr && p->p_Next->Value == value)
        {
            delete_node = p->p_Next;
            p->p_Next = delete_node->p_Next;
        }

    }

    if(delete_node != nullptr)
    {
        delete delete_node;
        delete_node = nullptr;
    }


}


#include <stack>

//struct ListNode {
//      int val;
//      struct ListNode *next;
//      ListNode(int x) :
//         val(x), next(NULL)
//      {}
//  };


//面试题06答案
vector<int> printListFromTailToHead(ListNode* head) {
    if(head == nullptr)
        return vector<int>();

    vector<int> ans;
    stack<ListNode*> print_s;
    ListNode* p = head;

    while(p !=  nullptr)
    {
        print_s.push(p);
        p = p->p_Next;
    }

    while(!print_s.empty()) {
        ans.push_back(print_s.top()->Value);
        print_s.pop();
    }

    return ans;
}

int main(){

    return 0;
}