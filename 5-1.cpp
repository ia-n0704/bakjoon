#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[20][20];
int n;
int ch[20];
ll mx,res;
void dfs(int x)
{
    if(x>n)
    {
        res=max(res,mx);
        return;
    }
    ch[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0)
        {
            ch[i]=1;
            mx+=arr[x][i];
            int nx=1;
            while(ch[nx]) nx++;
            dfs(nx);
            mx-=arr[x][i];
            ch[i]=0;
        }
    }
    ch[x]=0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n*(n-1)/2;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a][b]=arr[b][a]=c;
    }
    dfs(1);
    cout<<res;
}