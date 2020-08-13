#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <set>
using namespace std;




class Solution {
public:
    //////////////////////////////////////////排列
    vector<string> Permutation(string str) {
        set<string> ans;
        if(str.empty())
            return vector<string>();
        int index = 0;
        Permutation_(ans,str,index);
        return vector<string>(ans.begin(),ans.end());
    }

    void Permutation_(set<string>& ans,string& str,int index)
    {
        if(index == str.size())
        {
//            cout<<str<<endl;
            ans.insert(str);
            return;
        }
        else {
            for (int i = index; i < str.size(); ++i) {
                char temp = str[index];
                str[index] = str[i];
                str[i] = temp;

//                cout << "交换：" << str << endl;
                Permutation_(ans, str, index + 1);

                //退回位置
                temp = str[index];
                str[index] = str[i];
                str[i] = temp;
//                cout << "回退：" << str << endl;
            }
        }
    }

    //////////////////////////////////////组合
    vector<string> combination(string str)
    {
        if(str.empty())
            return vector<string>();

        set<string> ans;
        for(int i = 1; i <= str.size();++i)
        {
            for (int j = 0; j <= str.size() - i ; ++j) {
                string temp = str.substr(j,i);
                ans.insert(temp);
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
    ///////////////////////////////////////全排列组合
    vector<string> Permutation_Combination(string str)
    {
        if(str.empty())
            return vector<string>();

        set<string> ans;
        for(int i = 1; i <= str.size();++i)
        {
            for (int j = 0; j <= str.size() - i ; ++j) {
                string temp = str.substr(j,i);
//                ans.insert(temp);
                int index = 0;
                Permutation_(ans,temp,index);
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};

int main()
{

    Solution solution;
    auto p = solution.Permutation("abc");
    cout<<"排列"<<endl;
    for(auto str : p)
        cout<<str<<endl;

    p = solution.combination("abc");
    cout<<"组合"<<endl;
    for(auto str : p)
        cout<<str<<endl;

    cout<<"全排列组合"<<endl;
    p = solution.Permutation_Combination("abc");
    for(auto str : p)
        cout<<str<<endl;

}