#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int ch[1000010];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int a;
        cin>>a;
        ch[a]=1;
    }
    int res=0;
    for(int i=1;i<=n;i++)
        if(ch[i] || i<k) res++;
    cout<<res;
}