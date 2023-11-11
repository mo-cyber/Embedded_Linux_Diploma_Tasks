#include <iostream>
#include <regex>

int main()
{
    std::string branchName = "feature/TN-123/branchname";
    std::regex pattern("^feature/TN-[0-9]+/[A-Za-z0-9_]+$");

    if(std::regex_match(branchName, pattern))
    {
        std::cout<<"Valid Branch Name"<<std::endl;
    }
    else
    {
        std::cout<<"Invalid Branch Name"<<std::endl;
    }

    return 0;
}