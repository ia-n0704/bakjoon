#include <bits/stdc++.h>
using namespace std;
int f(int x)
{
    if(x<20) return 20-x;
    else if(x>25) return x-25;
    else return 0;
}
int main()
{
    int res=0;
    int c=0;
    for(int i=-5000;i<=5000;i++)
    {
        int temp=i;
        for(int j=1;j<=10;j++)
            temp=f(temp);
        if(temp==0)
        {
            cout<<i<<' ';
            res+=i;
            c++;
        }
    }
    cout<<'\n';
    cout<<c<<" "<<res<<" | "<<c+res;
}