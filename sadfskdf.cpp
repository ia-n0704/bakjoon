#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    cin>>n;
    for(int i=1;i<=10;i++)
    {
        double temp=n*15-45;
        cout<<"i="<<i-1<<" | ";
        cout<<setprecision(14)<<fixed<<temp<<' ';
        cout<<n-0.1*temp<<'\n';
        n=n-0.1*temp;  
        cout<<'\n'; 
    }
}