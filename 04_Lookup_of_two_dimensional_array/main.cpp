#include <iostream>
#include <vector>
using namespace std;




/**
 * 在array中查找target是否存在
 * @param target 搜索的目标
 * @param array 满足行从左到右，有序递增。列从上到下，有序递增。
 * @return 是否找到
 */
bool Find(int target, const vector<vector<int>>& array) {
    if(array.empty())
        return false;
    int rows = array.size();
    int columns = array[0].size();

    //从右上角逐步缩小范围
    int row = 0;
    int column = columns - 1;
    while(row < rows && column >= 0)
    {
        if(array[row][column] > target) //最后一列最小的数比目标大，排除最后一列
            --column;
        else if(array[row][column] < target) //最上一行最大的数比目标值小，排序最上一行
            ++row;
        else
            return true;
    }

    return false;
}

int main(){
    int rows = 4;
    int columns = 4;

    vector<vector<int>> res(rows,vector<int>(columns,0));
    res = {{1,2,8,9},
           {2,4,9,12},
           {4,7,10,13},
           {6,8,11,15}};

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<Find(14,res)<<endl;
    return 0;
}