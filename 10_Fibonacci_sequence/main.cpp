#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0,1};
        if(n < 2)
            return result[n];

        long long FunSum = 0;
        long long FunFirst = 0;
        long long FunSecond = 1;
        for(int i = 2; i <= n; ++i)
        {
            FunSum = FunSecond + FunFirst;
            FunFirst = FunSecond;
            FunSecond = FunSum;
        }

        return FunSum;
    }
};

int main(){
    Solution test1;
    for (int i = 0; i < 10; ++i) {
        cout<<test1.Fibonacci(i)<<endl;
    }
}