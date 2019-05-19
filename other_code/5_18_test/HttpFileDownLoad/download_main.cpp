#include"download.h"
void menu()
{
    int thread_number;
    string address;
    cout << "请输入下载地址:" << " ";
    cin >> address;
    int len = address.length();
    char *add = new char [len+1];
    address.copy(add, len, 0);
    add[len] = '\0';
    cout << "add:" << add << endl;
    cout << "请输入线程数量:\n";
    cin >> thread_number;
    if(thread_number>20 || thread_number<=0)
    {
        cout << "该线程数量不符合范围,已使用默认线程数量下载\n";
        thread_number = 5;
    }
    Baseclient myclient(thread_number, add);
    myclient.mysocket();
}
int main(int argc, char const *argv[])
{
    menu();
    return 0;
}

