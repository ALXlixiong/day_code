#include <algorithm>
using namespace std;
class Solution {
    public:
        /**
         *      *  奇数位上都是奇数或者偶数位上都是偶数
         *           *  输入：数组arr，长度大于2
         *                *  len：arr的长度
         *                     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
         *                          */
        void oddInOddEvenInEven(vector<int>& arr, int len) {
            int i = 0, j = 1;
            while(i < len && j < len){
                while(i < len && (arr[i] & 1) == 0) i += 2;
                while(j < len && (arr[j] & 1) == 1) j += 2;
                if(i < len && j < len) swap(arr[i], arr[j]);

            }

        }

};
