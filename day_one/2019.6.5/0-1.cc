#include <iostream>
using namespace std;

#define K 6
#define W 21

int arr[K][W] = {0};

int value[] = {0,3,4,5,8,10};
int weight[] = {0,2,3,4,5,9};


int main()
{
    for(int k = 1;k<K;++k){
        for(int cap = 1;cap<W;++cap){
            if(weight[k]>cap){
                //背包空间不足
                arr[k][cap] = arr[k-1][cap];
            }
            else
            {
                //空间足够，选择偷还是不偷
                int value1 = arr[k-1][cap-weight[k]]+value[k];
                int value2 = arr[k-1][cap];
                arr[k][cap] = value1>value2?value1:value2;
            }
        }
    }
    cout<<arr[K-1][W-1]<<endl;
    return 0;
}
