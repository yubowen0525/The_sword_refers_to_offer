#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define ERROR -1  //分母为0
class Solution {
public:
    //////////////////////////////////////////////////////
    //模拟进位思想
    void Print_n_digits_from_1_to_maximum(int n){
        if(n < 1)
            return;
        char ans[n]; //vector
        for (int i = 0; i < n; ++i) {
            ans[i] = '0';
        }
//        ans[n] = '\0';

        while(increatmen(ans,n))
        {
            print_ans(ans,n);
            cout<<" ";
        }
    }

    bool increatmen(char* res,int length)
    {
        bool iscarry = true;
//        int nLength = strlen(res);  //不会算'\0'

        //最后一位+1
        ++res[length-1];

        for (int i = length - 1; iscarry && i >= 0; --i) {
            iscarry = false;
            if(res[i] == '9'+1)
            {
                //溢出退出
                if(i - 1 < 0)
                    return false;

                //进位
                res[i] = '0';
                ++res[i-1];
                iscarry = true;
            }
        }

        return true;
    }


    void print_ans(char* ans,int n)
    {
        bool startprint = false;

        for (int i = 0; i < n; ++i) {
            if(ans[i] == '0' && !startprint)
                continue;

            startprint = true;
            cout<<ans[i];
        }

    }
    //////////////////////////////////////////////////////////
    //递归思想，全排列
//    void Print_n_digits(int n){
//        if(n < 1)
//            return;
//        int ans[n]; //vector
//        for (int i = 0; i < n; ++i) {
//            ans[i] = 0;
//        }
//
//        for (int i = 0; i < 10; ++i) {
//            ans[0] = i;
//            Print_n_digits_Recursive(ans,n,0);
//        }
//    }
//
//    void Print_n_digits_Recursive(int* ans,int length,int index)
//    {
//        if(length - 1 == index) {
//            print_ans(ans, length);
//            cout<<" ";
//            return;
//        }
//
//        for (int i = 0; i < 10; ++i) {
//            ans[index+1] = i;
//            Print_n_digits_Recursive(ans,length,index+1);
//        }
//    }

};

int main(){

    Solution solution;
    solution.Print_n_digits_from_1_to_maximum(2);
}