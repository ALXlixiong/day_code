链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue
来源：牛客网

#include <iostream>
using namespace std;
  
#define N 100001
 
bool isChange (int previous, int current, int next) {
    if ((current > previous && current > next) ||
        (current < previous && current < next)) {
        return true;
    }
    return false;
}
 
int main() {
    int n, arr[N];
    while (cin>>n) {
        int ans = 1, previous = 0;
        // 序列长度小于3，输出1
        if (n<3) cout << "1" << endl;
        for (int i=0; i<n; i++)
            cin >> arr[i];
        for (int i=1; i<n-1; i++) {
            // 当前数字与下一个数字相等，则跳过
            if (arr[i] == arr[i+1]) {
                continue;
            } else {
                // 若发生跳变，计数+1，指针+1。
                if (isChange(arr[previous], arr[i], arr[i+1])) {
                    ans++;
                    previous = ++i;
                } else {
                    previous = i-1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
