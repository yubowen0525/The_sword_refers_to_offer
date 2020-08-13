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
    /**
     * 方法1
     * @param pListHead
     * @param k
     * @return
     */
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr)
        {
            perror("链表为空");
            exit(1);
        }

        if(k < 1)
        {
            perror("输入k值有误");
            exit(1);
        }

        stack<ListNode*> s;
        ListNode* p = pListHead;

        while(p != nullptr)
        {
            s.push(p);
            p = p->next;
        }

        for (int i = 1; i < k; ++i) {
            s.pop();
        }

        if(!s.empty())
            return s.top();
        else
        {
            perror("k超出范围");
            exit(1);
        }

    }

    /**
     * 方法2 先获取长度，在找到n-k+1的node
     * @param pListHead
     * @param k
     * @return
     */
    ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k)
    {
        if(pListHead == nullptr)
            return nullptr;

        int length = get_length(pListHead);

        if(k < 1 || k > length)
            return nullptr;

        ListNode* p = pListHead;
        for (int i = 1; p != nullptr && i < length - k + 1; ++i) {
            p = p->next;
        }

        return p;
    }

    int get_length(ListNode* p)
    {
        int length = 0;
        while(p != nullptr)
        {
            ++length;
            p =  p->next;
        }
        return length;
    }

    /**
     * 双指针，两个指针保持k-1的距离
     * @param pListHead
     * @param k
     * @return
     */
    ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k)
    {
        if(pListHead == nullptr)
            return nullptr;

        if(k < 1)
            return nullptr;

        ListNode* Quick_p = pListHead;
        ListNode* Slow_p = nullptr;

        for(int i = 1;Quick_p != nullptr;Quick_p = Quick_p->next,++i)
        {
            if(i - k == 0)
                Slow_p = pListHead;
            else if(int(i - k) > 0)
                Slow_p = Slow_p->next;
        }

        if(Slow_p == nullptr)
            return nullptr;
        else
        {
            return Slow_p;
        }

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

    Solution solution;
    cout<<solution.FindKthToTail2(p1,0)->val<<endl;


}