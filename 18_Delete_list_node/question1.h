//
// Created by ybw on 2020/5/3.
//

#ifndef THE_SWORD_REFERS_TO_OFFER_QUESTION1_H
#define THE_SWORD_REFERS_TO_OFFER_QUESTION1_H
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////题目1
typedef struct ListNode* pNode;
struct ListNode
{
    ListNode(int value , pNode next)
            :m_nValue(value),m_pNext(next)
    {}
    int m_nValue;
    pNode m_pNext;
};


void DeleteNode(pNode* pListNode,pNode pToBeDeleted)
{
    if(pListNode == nullptr || pToBeDeleted == nullptr)
        return;

    pNode p = *pListNode;

    if(pToBeDeleted->m_pNext != nullptr)
    {
        pNode next = pToBeDeleted->m_pNext;
        //赋值
        pToBeDeleted->m_nValue = next->m_nValue;
        //删除下一个节点
        pToBeDeleted->m_pNext = next->m_pNext;
    } else  //下一个节点是空
    {
        if(p == pToBeDeleted)    //只有一个节点
            *pListNode = nullptr;


        while(p->m_pNext != pToBeDeleted)
            p = p->m_pNext;

        //此时p为删除节点的前一个节点,删除
        p->m_pNext = pToBeDeleted->m_pNext;
    }

}

void question1(){
    pNode p5 = new ListNode(5, nullptr);
    pNode p4 = new ListNode(4, p5);
    pNode p3 = new ListNode(3, p4);
    pNode p2 = new ListNode(2, p3);
    pNode p1 = new ListNode(1, p2);
//    pNode p1 = new ListNode(1, nullptr);

    pNode* head = &p1;

    pNode p = *head;
    while(p != nullptr)
    {
        cout<<p->m_nValue<<" ";
        p = p->m_pNext;
    }
    cout<<endl;


    DeleteNode(head,p1);

    p = *head;
    while(p != nullptr)
    {
        cout<<p->m_nValue<<" ";
        p = p->m_pNext;
    }
    cout<<endl;


}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif //THE_SWORD_REFERS_TO_OFFER_QUESTION1_H
