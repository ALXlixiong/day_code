#pragma once
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <unistd.h>

void handle_send(){};
class Finded
{
	private:
        boost::asio::ip::udp::endpoint sender_endpoint;
        boost::asio::io_service io_service;
	public:
		void FindedInit()
		{
			boost::asio::ip::udp::socket socket(io_service,
                        boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8080));
			while(1)
            {
                char arr[30] = {'0'};

                std::size_t bytes_transferred = 
                    socket.receive_from(boost::asio::buffer(arr), sender_endpoint);
                std::cout<<"DevName:"<<arr<<std::endl;
                std::cout << "remote host ip : " << sender_endpoint.address().to_string()
                          << std::endl;
                std::string str = "eth0....";
                socket.send_to(boost::asio::buffer(str), sender_endpoint);
                usleep(1000);
            }
		}

};
int main()
{
    Finded f;
    f.FindedInit();
    return 0;
}
