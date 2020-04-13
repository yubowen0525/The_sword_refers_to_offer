#include <iostream>
#include <stack>
#include <map>
using namespace std;

//////////////////////////////////////////查找重复数字1
// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false
bool duplicate(int numbers[], int length, int* duplication) {
    //除去异常值
    if(numbers == NULL || length == 0) return 0;
    //题目明确规定，在数组内的数字0-n-1的范围内。
    for(int i = 0; i<length;++i){
        if(numbers[i] < 0 || numbers[i] > length -1)
            return false;
    }

    for(int i = 0; i<length;++i){
        while(numbers[i] != i)
        {

            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }

            //交换 numbers[i]  与  numsber[numbers[i]]    这里要用temp，因为numbers[i]发生了改变
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }

    return false;
}

//////////////////////////////////////////查找重复数2
int countRange(const int* numbers,int length,int start,int end)
{
    if(numbers == nullptr)
        return 0;
    int count = 0;
    for(int i = 0;i< length;++i)
    {
        if(numbers[i] >= start && numbers[i]<= end)
            ++count;
    }

    return count;
}



int getDuplication(const int* numbers,int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    //如果里面的数超出了length错误
    for (int i = 0; i < length; ++i) {
        if(numbers[i] > length - 1  || numbers[i] < 1)
            return -2;
    }

    int left = 1;
    int right = length -1;
    while(left <= right)
    {
        int mid = ((right - left) >> 1) + left;
        int count = countRange(numbers,length,left,mid);    //下标left - mid 整个数组属于这个范围的应该有 left - mid + 1个

        if(left == right)   //已经探测到单个数
        {
            if(count > 1)
                return left;
            else
                break;
        }

        if(count > (mid - left + 1))    //证明在现在这个区间存在重复数，继续缩小范围
            right = mid;
        else
            left = mid + 1;

    }

    return -1;
}






int main()
{
    ///////////////////////////算法1
    int test1[] = {1,2,3,4,5,6,7,8,8};
    int ans = 0;
    duplicate(test1,9,&ans);
    cout<<ans<<endl;
    //////////////////////////算法2
    int test2[] = {1,2,3,4,5,6,7,8,8};
    cout<<getDuplication(test2,9)<<endl;

    return 0;
}
