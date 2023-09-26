#include <unistd.h>
#include <iostream>
#include <signal.h>

void signal_callback_handler(int signum)
{
    std::cout<<"Signal Interrupted"<<std::endl;
    exit(signum);
}

int main()
{
    signal(SIGINT, signal_callback_handler);
    while(true)
    {
        std::cout<<"Running..."<<std::endl;
        sleep(1);
    }

    return 0;
}