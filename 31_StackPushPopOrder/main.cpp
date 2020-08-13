#include <iostream>
#include <vector>
#include <stack>
using namespace std;



class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        if(pushV.empty() || popV.empty() || pushV.size() != popV.size())
            return false;

        stack<int> AssistStack;
        int index = 0;
        for (int i = 0; i < pushV.size(); ++i) {
            AssistStack.push(pushV[i]);
            while(index < popV.size() &&AssistStack.top() == popV[index])
            {
                AssistStack.pop();
                ++index;
            }
        }

        return AssistStack.empty();
    }
};

int main()
{
    Solution solution;
    cout<<solution.IsPopOrder({1,2,3,4,5},{4,3,5,1,2})<<endl;
}