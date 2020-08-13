#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void Insert(int num)
    {
        //当前容器总数是偶数，先放入右边的最小堆，再pop最小堆，放入左边的最大堆
        if(((max_heap.size() + min_heap.size()) & 1) == 0)
        {
            min_heap.push(num);
            int right_min = min_heap.top();
            min_heap.pop();
            max_heap.push(right_min);
        } else  //当前容器总数是奇数，先放入左边的最大堆，再pop最大堆的最大值，放入右边的最小堆
        {
            max_heap.push(num);
            int left_max = max_heap.top();
            max_heap.pop();
            min_heap.push(left_max);
        }
    }

    double GetMedian()
    {
        if((max_heap.size() + min_heap.size()) == 0)
            return 0;

            //偶数
        if(((max_heap.size() + min_heap.size()) & 1) == 0)
        {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else  //奇数
        {
            return max_heap.top();
        }

    }

public:
    priority_queue<int,vector<int>,greater<int>> min_heap;
    priority_queue<int,vector<int>,less<int>> max_heap;
};

int main()
{

    Solution solution;
//    for (int i = 1; i < 10; ++i) {
//        solution.Insert(i);
//    }

    for (int i = 1; i < -1; ++i) {
        solution.Insert(i);
    }
    auto p = solution.GetMedian();
    cout<<p<<endl;
}