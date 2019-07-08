#include<stdio.h>
int main(){
    int Arr[100001];
    int n = 0;
    Arr[0] = 1;
    Arr[1] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        Arr[i] = Arr[i - 1] + Arr[i - 2];
        Arr[i] = Arr[i] % 1000000;

    }
    while (scanf("%d",&n) != EOF){
        //前面补0,要用06d
        //printf((n < 29 ? "%d\n" : "%06d\n"),Arr[n]);
        printf("%d\n",Arr[n]);            
    }
    return 0;

}
