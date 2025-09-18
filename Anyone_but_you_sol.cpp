#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int x[200010];
int ch[200010];
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    cin>>a>>b;
    for(int i=1;i<a;i++)
    {
        cin>>x[i];
        ch[x[i]]=1;
    }

    int flag=0;
    if(a>b)
    {
        int no;
        if(x[b]%2) no=x[b]+1;
        else no=x[b]-1;
        for(int i=1;i<=2*n;i++)
            if(!ch[i] && i!=no) flag=1;
    }
    else
    {
        for(int i=1;i<=2*n;i+=2)
            if(ch[i]^ch[i+1]) flag=1;
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
}