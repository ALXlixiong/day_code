#pragma once
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <thread>
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

void handle_send(){};

class Finder
{
public:
	void FinderInit()
	{
		namespace ip = boost::asio::ip;
        boost::asio::io_service io_service;
        // Server binds to any address and any port.
        ip::udp::socket socket(io_service, ip::udp::endpoint(ip::udp::v4(), 0));

        while(1)
        {
        		socket.set_option(boost::asio::socket_base::broadcast(true));

                ip::udp::endpoint broadcast_endpoint(ip::address_v4::broadcast(), 8080);
                // Broadcast data.
                std::string str = "1234";
                // socket.send_to(boost::asio::buffer(buffer), broadcast_endpoint);
                socket.async_send_to(boost::asio::buffer(str), broadcast_endpoint,
                        boost::bind(&handle_send));
                std::cout<<"finder send ...\n";
                char arr[30] = {'0'};
                std::size_t bytes_transferred = 
                    socket.receive_from(boost::asio::buffer(arr), broadcast_endpoint);
                io_service.run();
                std::cout<<"DevName:"<<arr<<std::endl;
                // std::thread run_thread([&]{ io_service.run(); });
                // run_thread.join();
                usleep(1000);
        }
	}
};
int main()
{
    Finder f;
    f.FinderInit();
    return 0;
}
