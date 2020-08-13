#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x,struct RandomListNode * next= nullptr, struct RandomListNode * random = nullptr) :
            label(x), next(next), random(random) {
    }
};


class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
//        RandomListNode* ans = nullptr;
        Clone_Node(pHead);
        Clone_Random(pHead);
        return Clone_resolve(pHead);

    }

    /**
     * A->A'->B->B'->C->C'
     * @param pHead
     */
    void Clone_Node(RandomListNode* pHead)
    {
        auto p = pHead;
        while(p != nullptr)
        {
            auto p_clone = new RandomListNode(p->label);
            p_clone->next = p->next;
            p->next = p_clone;

            //更新p
            p = p_clone->next;
        }
    }


    void Clone_Random(RandomListNode* pHead)
    {
        auto p = pHead;
        while(p != nullptr)
        {
            if(p->random != nullptr)
            {
                auto p_clone = p->next;
                p_clone->random = p->random->next;
            }

            p = p->next->next;
        }
    }

    RandomListNode *Clone_resolve(RandomListNode *head)
    {
        RandomListNode *pNode = head;
        RandomListNode *result = head->next;
        while (pNode != NULL)
        {
            RandomListNode *pClone = pNode->next;
            pNode->next = pClone->next;
            pNode = pNode->next;
            if (pNode != NULL)
                pClone->next = pNode->next;

        }
        return result;
    }

    RandomListNode* Clone_resolve(RandomListNode* pHead)
    {
        auto p = pHead;
        auto p_head = pHead->next;
        auto p_clone = p_head;

        while(p != nullptr)
        {
            p->next = p->next->next;
            if(p_clone->next != nullptr)
                p_clone->next = p_clone->next->next;

            //更新 p , p_clone
            p = p->next;
            p_clone = p_clone->next;
        }

        return p_head;
    }
};

int main()
{

    RandomListNode*  p4 = new RandomListNode(4);
    RandomListNode*  p3 = new RandomListNode(3, p4);
    RandomListNode*  p2 = new RandomListNode(2, p3,p3);
    RandomListNode*  p1 = new RandomListNode(1, p2,p4);

    Solution solution;
    auto ans = solution.Clone(p1);
    while(p1 != nullptr)
    {
        cout<<p1->label<<" "<<p1->random<<" "<<endl;
        p1 = p1->next;
    }

    cout<<endl;

    while(ans != nullptr)
    {
        cout<<ans->label<<" "<<ans->random<<" "<<endl;
        ans = ans->next;
    }

}