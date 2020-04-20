#include <iostream>
#include <iterator>
#include <regex>
#include <string>
using namespace std;


void replaceSpace(char *str,int length) {
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if(str[i] == ' ')
            ++count;
    }

    int str2_length = count*2 + length;
//    char str2[str2_length]; //变量不能初始化

    int str1_index =  length - 1;
    int str2_index = str2_length - 1;
    while(str1_index >= 0 && str2_index >=0)
    {
        if(str[str1_index] != ' ')
            str[str2_index--] = str[str1_index--];
        else{
            str[str2_index--] = '0';
            str[str2_index--]= '2';
            str[str2_index--] = '%';
            --str1_index;
        }

    }

}



int main(){
//    cout<<replace_test(str,test1," ")<<endl;
    char* test1 = new char[30];
    strcpy(test1,"hello world");
    replaceSpace(test1,strlen("hello world")+1);
    return 0;
}