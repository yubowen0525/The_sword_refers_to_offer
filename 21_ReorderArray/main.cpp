#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
//    typedef bool(*Fun_P)(vector<int>&,int);
    void reOrderArray1_Core(vector<int> &array, bool(*func)(vector<int>&,int))
    {
        int left = 0;
        int right = array.size() - 1;

        while(left < right)
        {
            //找偶数，左边奇数就后移
            while(left < right && (func(array,left)))
                ++left;

            //找奇数，右边偶数就前移
            while(left < right && (!func(array,right)))
                --right;

            if(left < right)
            {
                int temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }
    }

    //偶数返回false,奇数返回true;
    static bool fun(vector<int> &array,int index)
    {
        return array[index] & 1;
    }


    void reOrderArray1(vector<int> &array)
    {
        reOrderArray1_Core(array,fun);
    }


    void reOrderArray(vector<int> &array)
    {
        int size = array.size();
        //冒泡排序，将偶数从后面，泡出到头部
        for(int i = 0;i < array.size();++i)
        {
            for(int j =  array.size() - 1;j > i ;--j)
            {
                //前偶后奇交换
                if((array[j] & 1) ==  1&& (array[j - 1] & 1) == 0)
                {
                    int temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = temp;
                }
            }
        }
    }
};


int main()
{
    vector<int> v = {2,4,6,1,3,5,7};
    Solution solution;
    solution.reOrderArray1(v);

    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}