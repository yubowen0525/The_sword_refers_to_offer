#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <set>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int middle = numbers.size() / 2;
        int start = 0;
        int end = numbers.size()-1;
        int index = Partition(numbers,start,end);
        while(index != middle)
        {
            if(index < middle)
            {
                start = index + 1;
                index = Partition(numbers,start,end);
            }
            else if (index > middle)
            {
                end = index - 1;
                index = Partition(numbers,start,end);
            }
        }

        return Check_IsVaild(numbers,numbers[index]);
    }

    int Partition(vector<int>& numbers,int start , int end)
    {
        int length = end - start + 1;
        int index = random() % length + start;
        int small = -1;
        swap(numbers[index],numbers[end]);
        for (int i = start; i < end; ++i) {
            if(numbers[i] <= numbers[end])
            {
                ++small;
                if(small != i)
                    swap(numbers[small],numbers[i]);
            }
        }

        ++small;
        swap(numbers[small],numbers[end]);
        return small;
    }

    void swap(int& a,int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int Check_IsVaild(vector<int>& numbers,int value)
    {
        int times = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if(value == numbers[i])
                ++times;
        }

        return times * 2 > numbers.size() ? value : 0;

    }

};

int main()
{

    Solution solution;
    auto p = solution.MoreThanHalfNum_Solution({1,2,3,2,2,2,5,4,2});
    cout<<p<<endl;

}