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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr)
            return nullptr;

        ListNode* ReverseHead = nullptr;
        ListNode* pNode = pHead;
        ListNode* pNext = nullptr;
        ListNode* prev = nullptr;
        while(pNode != nullptr)
        {

            //更新下一个节点
            pNext = pNode->next;
            if(pNext == nullptr)
            {
                ReverseHead = pNode;
            }

            //反转当前节点
            pNode->next = prev;
            //更新当前节点与前一个节点,向后走一步
            prev = pNode;
            pNode = pNext;
        }

        return ReverseHead;
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
    auto test = solution.ReverseList(p1);

    while(test!= nullptr)
    {
        cout<<test->val<<endl;
        test = test->next;
    }


}