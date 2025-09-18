#import<iostream>
int main()
{
    int a,b;
    std::cin>>a>>b;
    std::cout<<(b+b%2-a+((a%2)^1)+1)/2;
} 