    #include <bits/stdc++.h>

int main()
{
    int a,b,c;
    std::cout<<"Enter 3 triangle sides: ";
    std::cin>>a>>b>>c;
    a = pow(a,2);
    b = pow(b,2);
    c = pow(c,2);
    if((a == b + c) || (b == a + c) || (c == b + a))
    {
        std::cout<<"Yes, right angle triangle.";
    }  
    else
    {
        std::cout<<"No, not right angle triangle.";
    }

    return 0;
}