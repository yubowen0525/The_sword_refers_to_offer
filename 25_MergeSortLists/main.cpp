#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x,struct ListNode * next) :
            val(x), next(next) {
    }
};


class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr && pHead2 == nullptr)
            return nullptr;

        ListNode* L = new ListNode(0, nullptr);
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* pc = L;
        while(p1 && p2)
        {
            //p1比较小
            if(p1->val <= p2->val)
            {
                pc->next = p1;
                //更新p1
                p1 = p1->next;
            } else  //p2比较小
            {
                pc->next = p2;
                p2 = p2->next;
            }
            //L下移动
            pc = pc->next;
        }
        if(p1)  //p1还有
        {
            pc->next = p1;
        }
        else if(p2)
        {
            pc->next = p2;
        }

        ListNode* p = L->next;
        delete L;
        return p;
    }
};

int main()
{
    ListNode* p7 = new ListNode(12, nullptr);
    ListNode*  p6 = new ListNode(10, p7);
    ListNode*  p5 = new ListNode(8, p6);
    ListNode*  p4 = new ListNode(7, p5);
    ListNode*  p3 = new ListNode(5, p4);
    ListNode*  p2 = new ListNode(3, p3);
    ListNode*  p1 = new ListNode(1, p2);

    ListNode* d7 = new ListNode(7, nullptr);
    ListNode*  d6 = new ListNode(6, d7);
    ListNode*  d5 = new ListNode(5, d6);
    ListNode*  d4 = new ListNode(4, d5);
    ListNode*  d3 = new ListNode(3, d4);
    ListNode*  d2 = new ListNode(2, d3);
    ListNode*  d1 = new ListNode(1, d2);


//    p7->next = p3;

    Solution solution;
    auto test = solution.Merge(p1,d1);

    while(test!= nullptr)
    {
        cout<<test->val<<endl;
        test = test->next;
    }


}