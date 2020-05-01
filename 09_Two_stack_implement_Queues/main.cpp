#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        //如果堆栈2是空
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if(stack2.empty())
            new logic_error("queue is empty");


        int value = stack2.top();
        stack2.pop();
        return value;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Solution test1;
    for (int i = 0; i < 10; ++i) {
        test1.push(i);
    }

    for (int j = 0; j < 10; ++j) {
        cout<<test1.pop()<<endl;
    }

}