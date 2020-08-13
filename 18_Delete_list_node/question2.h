//
// Created by ybw on 2020/5/3.
//

#ifndef THE_SWORD_REFERS_TO_OFFER_QUESTION2_H
#define THE_SWORD_REFERS_TO_OFFER_QUESTION2_H
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////题目1
typedef struct ListNode* pNode;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x, ListNode* next = nullptr) :
            val(x), next(next) {
    }
};



class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead== nullptr || pHead->next== nullptr){return pHead;}
        ListNode* head = pHead;
        ListNode* p = pHead;
        ListNode* pre = nullptr;

        while(p->next != nullptr)
        {
            if(p->val == p->next->val)
            {
                //解决连续重复的问题
                while(p->next != nullptr && p->val == p->next->val) p = p->next;

                //后面全是重复的
                if(p->next == nullptr)
                {
                    if(pre != nullptr)
                    {
                        pre->next = nullptr;
                        return head;
                    }
                    else
                    {
                        return nullptr;
                    }

                }
                else
                {
                    if(pre != nullptr)
                    {
                        pre->next = p->next;
                        p = p->next;
                        continue;
                    }
                    else
                    {
                        head = p->next;
                        p = p->next;
                        continue;
                    }
                }

            }
            pre = p;
            p = p->next;
        }

        return head;
    }
};

void question2(){
    pNode p7 = new ListNode(3, nullptr);
    pNode p6 = new ListNode(3, p7);
    pNode p5 = new ListNode(3, p6);
    pNode p4 = new ListNode(3, p5);
    pNode p3 = new ListNode(3, p4);
    pNode p2 = new ListNode(3, p3);
    pNode p1 = new ListNode(3, p2);
//    pNode p1 = new ListNode(1, nullptr);

    pNode* head = &p1;

    pNode p = *head;
    while(p != nullptr)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;


    Solution solution;
    p = solution.deleteDuplication(*head);

//    p = *head;
    while(p != nullptr)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;


}

#endif //THE_SWORD_REFERS_TO_OFFER_QUESTION2_H
