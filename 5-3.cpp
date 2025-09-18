#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[25][25];
int ch[25];
int n;
ll l;
ll mx;
int flag;
int st;
void dfs(int x,int cnt)
{
    if(mx>l) return;
    if(cnt>=n)
    {
        if(arr[x][st]==0) return;
        if(mx+arr[x][st]==l) flag=1;
        return;
    }
    ch[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0)
        {
            if(arr[x][i]==0) continue;
            mx+=arr[x][i];
            dfs(i,cnt+1);
            mx-=arr[x][i];
        }
    }
    ch[x]=0;
}
int main()
{
    cin>>n>>l;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>arr[i][j];
    for(int i=1;i<=n;i++)
    {
        mx=0;
        st=i;
        dfs(i,1);
        fill(ch,ch+n+1,0);
        if(flag) break;
    }
    if(flag) cout<<"possible";
    else cout<<"impossible";
}