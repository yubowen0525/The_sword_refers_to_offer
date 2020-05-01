#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
            return false;
        bool* visit = new bool[rows*cols];
        memset(visit, false,rows*cols);
        int pathLength = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(hasPathCore(matrix,rows,cols,i,j,str,pathLength,visit))
                    {
                        delete[] visit;
                        return true;
                    }
            }
        }

        delete[] visit;
        return false;
    }

    /**
     *
     * @param matrix
     * @param rows
     * @param cols
     * @param row 当前行
     * @param col 当前列
     * @param str
     * @param pathLength 访问长度
     * @param visit 标记矩阵
     * @return 矩阵存在str路径
     */
    bool hasPathCore(char* matrix, int rows, int cols, int row,int col,char* str,int& pathLength,bool* visit)
    {
        //整个结束条件
        if(str[pathLength] == '\0')
            return true;

        bool hasPath = false;
        int index = row*cols+col;
        //字符相等，且该位置没有访问过
        if(row >= 0 && row < rows && col >= 0 && col < cols
            && matrix[index] == str[pathLength]
            && !visit[index])
        {
            visit[index] = true;
            ++pathLength;
            hasPath = hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visit) ||
                    hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visit) ||
                    hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visit) ||
                    hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visit);

            //退后,清除标记    减去hasPath返回true的退出
            if(!hasPath) {
                --pathLength;
                visit[index] = false;
            }

        }

        return hasPath;
    }


};


int main(){
    Solution solution;
    char test[] = "ABCESFCSADEE";

    cout<<solution.hasPath(test,3,4,"ABCCED")<<endl;


}