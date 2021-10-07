#include <iostream>
#include "asio.hpp"
int main()
{
    asio::io_context io_context;
    std::cout << "QAQ" << std::endl;
    asio::steady_timer timer(io_context, asio::chrono::seconds(5));
    timer.wait();
    std::cout << "QwQ" << std::endl;
    return 0;
}

