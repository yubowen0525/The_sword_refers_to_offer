#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

struct compare {
    bool operator()(int a, int b) const
    {
        string str1 = to_string(a) + to_string(b);
        string str2 = to_string(b) + to_string(a);
        return str1 < str2;
    }
};

multiset<int,compare> test;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty())
            return "";

        for (int i = 0; i < numbers.size(); ++i) {
            test.insert(numbers[i]);
        }

        string ans;
        for(auto num : test)
        {
            ans += to_string(num);
        }

        return ans;
    }
};
int main()
{

    Solution solution;

    cout<<solution.PrintMinNumber({3,32,321})<<endl;

}