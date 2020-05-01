#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows <= 0 || cols <= 0 || threshold < 0)
            return 0;

        //建立visit
        bool* visit = new bool[rows*cols];
        memset(visit, false,rows*cols);

        int count = movingCountCore(threshold,rows,cols,0,0,visit);

        delete[] visit;

        return count;
    }


    int movingCountCore(int threshold, int rows, int cols,int row,int col,bool* visit)
    {
        //全部终止条件是什么？
        //不需要终止条件

        int count = 0;
        int index = row*cols + col ;
        if(row >= 0 && col >= 0 && row < rows && col < cols
            && check_threshold(threshold,row,col)
            && !visit[index])
        {
            visit[index] = true;

            count = 1 + movingCountCore(threshold,rows,cols,row - 1,col,visit)
                    + movingCountCore(threshold,rows,cols,row,col+1,visit)
                    + movingCountCore(threshold,rows,cols,row+1,col,visit)
                    + movingCountCore(threshold,rows,cols,row,col-1,visit);

            //没有回退操作

        }

        return count;


    }



    /**
     * 检查是否超过threshold
     * @param threshold
     * @param row
     * @param col
     * @return
     */
    bool check_threshold(int threshold, int row, int col)
    {
        return Get_DigitSum(row) + Get_DigitSum(col) <= threshold;
    }

    int Get_DigitSum(int number)
    {
        int result = 0;
        while(number > 0)
        {
            result += number % 10;
            number /= 10;
        }
        return result;
    }




};


int main(){
    Solution solution;
    cout<<solution.movingCount(3,3,4)<<endl;


}