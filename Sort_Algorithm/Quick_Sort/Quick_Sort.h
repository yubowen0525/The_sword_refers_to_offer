//
// Created by ybw on 2020/4/23.
//

#ifndef THE_SWORD_REFERS_TO_OFFER_QUICK_SORT_H
#define THE_SWORD_REFERS_TO_OFFER_QUICK_SORT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;

void Swap(int& left , int& right)
{
    int temp = right;
    right = left;
    left = temp;
}

int Rand(int left , int right)
{
    if(right < left)
    {
        Swap(left,right);
    }

    return rand() % (right - left + 1) + left;
}

int Partition(vector<int>& res,int start,int end)
{
    if(res.empty() || start < 0 || end >= res.size())
        throw logic_error("invail input");

    int index = Rand(start,end);
    int small = start -1;
    Swap(res[index],res[end]);
    for(index = start;index < end;++index)
    {
       if(res[index] < res[end])
       {
           ++small;
           if (small != index)
               Swap(res[small], res[index]);
       }
    }

    ++small;
    Swap(res[small],res[end]);
    return small;
}


void QuickSort(vector<int>& res,int start,int end)
{
    if(start == end)
        return;

    int index = Partition(res,start,end);   //随机找一个P点，使左边的都比P小，右边的都比P大。

    if(index > start)   //左边继续划分
        QuickSort(res,start,index-1);
    if(index < end)     //右边继续划分
        QuickSort(res,index+1,end);

}








#endif //THE_SWORD_REFERS_TO_OFFER_QUICK_SORT_H
