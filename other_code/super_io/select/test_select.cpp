#include <iostream>
#include <sys/select.h>
#include <unistd.h>

int main()
{
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(0,&read_fds);

    for(;;)
    {
        struct timeval time;
        time.tv_sec = 3;
        time.tv_usec = 0;
        int ret= select(1,&read_fds,nullptr,nullptr,&time);
        if(ret<0){
            std::cout<<"select error\n";
            continue;
        }
        else if(ret == 0)
        {
            std::cout<<"time out of range\n";
            FD_ZERO(&read_fds);
            FD_SET(0,&read_fds);
            continue;
        }
        else
        {
            std::cout<<"get "<<ret<<std::endl;
        }

        if(FD_ISSET(0,&read_fds))
        {
            char buf[1024];
            ssize_t size = read(0,buf,sizeof(buf)-1);
            buf[size] = '\0';
            std::cout<<buf<<"\n";
        }
        else
        {
            std::cout<<"error,invalid fd\n";
            continue;
        }
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
    }
    return 0;
}
