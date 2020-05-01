#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    //做笔试题中get到的方法
    int  NumberOf1(int n) {
        int result = 0;
        while(n)
        {
            ++result;
            n &= n - 1;
        }

        return result;
    }

    int  nmberOf1(int n) {
        int result = 0;
        unsigned int flag = 1;
        while(flag)
        {
            if(n & flag)
                ++result;

            flag <<= 1;
        }

        return result;
    }
};

int main(){
    Solution solution;
    cout<<solution.nmberOf1(7)<<endl;


}