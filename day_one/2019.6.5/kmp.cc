#include <iostream>
using namespace std;
#include <string.h>
void GetNextValue(char *child,int next[])
{
    int len = strlen(child);
    next[0] = 0;
    int j = 0;//表示现在匹配的长度
    for(int i = 1;i<len;){
        if(child[j] == child[i])
        {
            ++j;
            next[i] = j;
            ++i;
        }
        else
        {
            if(j>0)
                j = next[j-1];
            else
                next[i++] = 0;
        }
    }
}

void MoveFirstNum(int *next,int len)
{
    for(int i = len-1;i>0;--i){
        next[i] = next[i-1];
    }
    next[0] = -1;
}

void KmpSearchFunc(char *text,char *child)
{
    int child_len = strlen(child);
    int *next = new int[child_len];
    GetNextValue(child,next);
    MoveFirstNum(next,child_len);
    int i = 0;
    int j = 0;
    int text_len = strlen(text);
    while(i<text_len){
        if(j == child_len -1){
            cout<<i-j<<endl;
            j = next[j];
        }
        if(text[i] == child[j]){
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
            if(j == -1){
                ++i;
                ++j;
            }
        }
    }
    delete[] next;
}

int main()
{
    char *text = "ABABABCABAABABCABAA";
    char *child = "ABABCABAA";
    KmpSearchFunc(text,child);
    //int len = strlen(child);
    //int *next = new int[len];
    //GetNextValue(child,next);
    //MoveFirstNum(next,len);
    //for(int i = 0;i<len;++i){
    //    cout<<next[i]<<endl;
    //}
    return 0;
}
