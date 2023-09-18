#include <iostream>
#include <algorithm>

int main()
{
    int x,y,z,ans;
    std::cin>>x>>y>>z;
    ans = std::max(x,std::max(y,z));
    std::cout<<"Maximum: "<<ans<<std::endl;

    return 0;
}