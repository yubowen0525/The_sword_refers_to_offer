#include <iostream>
#include <vector>
#include <stack>
using namespace std;



class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int Down_boundary = matrix.size() - 1;
        if(Down_boundary < 0)
            return vector<int>();
        int right_boundary = matrix[0].size() - 1;
        if(right_boundary < 0)
            return vector<int>();

        vector<int> ans;
        int Up_boundary = 0;
        int left_boundary = 0;
        int i = 0,j=-1;
        while(i < Down_boundary || j < right_boundary)
        {
            while(j < right_boundary)
            {
                ++j;
                ans.emplace_back(matrix[i][j]);
            }
            ++Up_boundary;
            if(Up_boundary > Down_boundary)
                break;
            //准备下移
            while(i < Down_boundary)
            {
                ++i;
                ans.emplace_back(matrix[i][j]);
            }
            --right_boundary;
            if(left_boundary > right_boundary)
                break;
            //准备左移

            while(j > left_boundary)
            {
                --j;
                ans.emplace_back(matrix[i][j]);
            }

            --Down_boundary;
            if(Up_boundary > Down_boundary)
                break;
            //右移
            while(i > Up_boundary)
            {
                --i;
                ans.emplace_back(matrix[i][j]);
            }
            //上移
            ++left_boundary;
            if(left_boundary > right_boundary)
                break;
        }
        return ans;
    }

};

int main()
{


    vector<vector<int> > matrix = {{1,2,3,4},
                                   {5,6,7,8},
                                   {9,10,11,12},
                                   {13,14,15,16}};

    vector<vector<int> > matrix1 = {{1}};
    vector<vector<int> > matrix2 = {{1},
                                    {2},
                                    {3},
                                    {4},
                                    {5}};
    Solution solution;
    vector<int> ans = solution.printMatrix(matrix);

    for (auto x : ans) {
        cout<<x<<endl;
    }

}