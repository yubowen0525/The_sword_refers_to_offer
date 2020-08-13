#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int GetTransltationCount(int number) {
        if(number < 0)
            return -1;
        string str_number = to_string(number);
        return GetTransltationCount(str_number);
    }

    int GetTransltationCount(string number) {
        int length = number.size();
        vector<int> temp(length,0);
        if(length > 0)
            temp[0] = 1;
//        cout << number.substr(length - 2, 2) << endl;
        if(length > 1 && number.substr(length - 2, 2) >= "10" && number.substr(length - 2, 2) <= "25")
            temp[1] = 2;
        else
            temp[1] = 1;

        for (int i = 2; i < length; ++i) {
//            cout<<number.substr(length-i-1,2)<<endl;
            if(number.substr(length-i-1,2) >= "10" && number.substr(length-i-1,2) <= "25")
                temp[i] = temp[i - 1] + temp[i - 2];
            else
                temp[i] = temp[i - 1];
        }
        return temp[length - 1];
    }
};



int main()
{
//    Solution solution;
////    cout<<solution.GetTransltationCount(0)<<endl;
//    cout<<solution.GetTransltationCount(123)<<endl;
//    cout<<solution.GetTransltationCount(12258)<<endl;
//    cout<<solution.GetTransltationCount(12222)<<endl;


    long l1 = 1L;
    long l2 = 2147483647L;
    long l3 = 9876543210L;
    long l4 = 1234566789123456789L;
    int i = (int)l1;
    int i2 = (int)l2;
    int i3 = (int)l3;
    int i4 = (int)l4;
    cout<<i<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<endl;
}