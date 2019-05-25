#include <iostream>
#include <unistd.h>
#include <fcntl.h>

class Solution
{
    public:
        static void SetNoBlock(int fd){
            int fl = fcntl(fd,F_GETFL);
            if(fl < 0){
                std::cerr<<"fcntl error\n";
                return;
            }
            fcntl(fd,F_SETFL,fl | O_NONBLOCK);
        }
};


void test()
{
    Solution::SetNoBlock(0);
    while(1){
        char buf[1024] = {0};
        int size = read(0,buf,sizeof(buf)-1);
        if(size < 0){
            std::cerr<<"read error\n";
            sleep(1);
            continue;
        }
        buf[size] = '\0';
        std::cout<<buf<<std::endl;
    }
}

int main()
{
    test();
    return 0;
}
