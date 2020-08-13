#include <iostream>
#include <vector>
#include <stack>
using namespace std;



class Solution {
public:
    void push(int value) {
        MyStack.push(value);

        if(!AssistStack.empty())
        {
            //与栈顶比较，插入最小的值
            int top_value = AssistStack.top();
            top_value = ::min(top_value,value);
            AssistStack.push(top_value);

        } else
            AssistStack.push(value);

    }

    void pop() {
        MyStack.pop();
        AssistStack.pop();
    }

    int top() {
        return MyStack.top();
    }

    int min() {
        return AssistStack.top();
    }

private:
    stack<int> MyStack;
    stack<int> AssistStack;
};

int main()
{
    Solution solution;
    solution.push(3);
    cout<<solution.top()<<" "<<solution.min()<<endl;
    solution.push(4);
    cout<<solution.top()<<" "<<solution.min()<<endl;
    solution.push(1);
    cout<<solution.top()<<" "<<solution.min()<<endl;
    solution.push(5);
    cout<<solution.top()<<" "<<solution.min()<<endl;
    solution.pop();
    cout<<solution.top()<<" "<<solution.min()<<endl;
    solution.pop();
    cout<<solution.top()<<" "<<solution.min()<<endl;
    solution.push(2);
    cout<<solution.top()<<" "<<solution.min()<<endl;
}