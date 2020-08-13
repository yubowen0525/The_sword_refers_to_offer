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

#include <unordered_set>

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return nullptr;

        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        do
        {
            p1 = p1->next->next;
            p2 = p2->next;
        }while(p1->next != nullptr && p1->next->next != nullptr && p2->next != nullptr &&p1 != p2);

        //有环
        if(p1!= nullptr && p2!= nullptr && p1 == p2)
        {
            //得到环的大小
            int i = 1;
            ListNode* myself = p1;
            p1 = p1->next;
            for (;p1 != myself; ++i) {
                p1 = p1->next;
            }

            //第二次左右快速
            p1 = pHead;
            p2 = pHead;
            while(i--){p1 = p1->next;}

            while(p1 != p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }

            return p1;

        }

        return nullptr;


    }
};

int main()
{
    ListNode* p7 = new ListNode(7, nullptr);
    ListNode*  p6 = new ListNode(6, p7);
    ListNode*  p5 = new ListNode(5, p6);
    ListNode*  p4 = new ListNode(4, p5);
    ListNode*  p3 = new ListNode(3, p4);
    ListNode*  p2 = new ListNode(2, p3);
    ListNode*  p1 = new ListNode(1, p2);

//    p7->next = p3;

    Solution solution;
    cout<<solution.EntryNodeOfLoop(p1)->val<<endl;


}