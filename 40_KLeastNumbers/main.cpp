#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    ///////////////////////////////////////////快排的思想
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size()==0||k==0||k>input.size())
            return vector<int>();
        int length = input.size();
        int start = 0;
        int end = length - 1;
        int index = Partition_(input,start,end);
        while(index != k)
        {
            if(index < k)
            {
                start = index + 1;
                index = Partition_(input,start,end);
            }

            if(index > k)
            {
                end = index - 1;
                index = Partition_(input,start,end);
            }
        }

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(input[i]);
        }

        return ans;
    }


    int Partition_(vector<int>& v,int start,int end)
    {
        srandom(time(NULL));
        int length = end - start + 1;
        cout<<length<<endl;
        int index = rand() % length + start;
        int small = start - 1;
        swap(v[index],v[end]);
        for (int i = start; i < end; ++i) {
            if(v[i] <= v[end])
            {
                ++small;
                if(small != i)
                    swap(v[i],v[small]);
            }
        }
        ++small;
        swap(v[small],v[end]);
        return small;
    }

    void swap(int& a , int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    ////////////////////////////////////////////堆的思想
    vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
        if(input.size()==0||k==0||k>input.size())
            return vector<int>();
        priority_queue<int,vector<int>> max_heap;
        //先加入K个数
        for (int i = 0; i < k; ++i) {
            max_heap.push(input[i]);
        }

        for (int i = k; i < input.size(); ++i) {
            if(max_heap.top() > input[i])
            {
                max_heap.pop();
                max_heap.push(input[i]);
            }
        }

        vector<int> ans;
        int length = max_heap.size();
        for (int i = 0; i < length; ++i) {
            ans.push_back(max_heap.top());
            max_heap.pop();
        }

        return ans;
    }
};

int main()
{

    Solution solution;
    auto p = solution.GetLeastNumbers_Solution2({4,5,1,6,2,7,3,8},4);
    for(auto num : p)
        cout<<num<<endl;

}