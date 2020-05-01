#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;

        //没有用left < right 的原因是 ：数组搬了0个到后面，则本身有序
        //若元素存在重复怎么办
        while(rotateArray[left] >= rotateArray[right])
        {
            if(left + 1 == right)
            {
                left = right;
                break;
            }

            int mid = (left + right)/2;
            //中间节点大于最左节点，证明在左序列递增
            if(rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[right])
                --right;
            else if(rotateArray[left] <= rotateArray[mid])
                left = mid;
                //else if(rotateArray[mid] <= rotateArray[right])
            else
                right = mid;
        }

        return rotateArray[left];

    }
};


int main(){
    Solution solution;
    cout<<solution.minNumberInRotateArray({1,1,0,1,1})<<endl;


}