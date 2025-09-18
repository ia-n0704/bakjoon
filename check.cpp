#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    long long res=1;
    for(int i=1;i<=n;i++)
        res*=i;
    if(res%m==0) cout<<1;
    else cout<<0;
}