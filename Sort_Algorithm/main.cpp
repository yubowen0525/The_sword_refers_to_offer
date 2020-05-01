#include <iostream>
#include <stack>
#include "Quick_Sort/Quick_Sort.h"
using namespace std;




int main(){

    vector<int> test = {6,5,4,3,2,1,0};
    QuickSort(test,0,test.size()-1);
    for (auto num : test) {
        cout<<num<<" ";
    }
//    srand((int)time(nullptr));
//    default_random_engine e;
//    uniform_int_distribution<int> test1(1,5);
//    for (int i = 0; i < 100; ++i) {
//        cout<<test1(e)<<endl;
//    }
}