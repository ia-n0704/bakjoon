#include <bits/stdc++.h>
using namespace std;
double arr[200010],c[200010],p[200010];
int main()
{
    arr[0]=3;
    arr[1]=6;
    for(int i=2;i<=20000;i++)
    {
        if(i%2) arr[i]=4;
        else arr[i]=1;
    }
    c[0]=arr[0];
    for(int i=1;i<=20000;i++)
    {
        c[i]=arr[0];
        double temp=0;
        for(int j=i;j>=1;j--)
        {
            temp+=arr[j];
            temp=1.0/temp;
        }
        c[i]+=temp;
    }
    cout<<setprecision(10)<<c[20000];
}