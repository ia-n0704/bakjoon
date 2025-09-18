#include <bits/stdc++.h>
using namespace std;
int arr[4024][4024];
int ch[4024];
int n,m;
void dfs(int v)
{
    if(ch[v]) return;
    ch[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(arr[v][i]) dfs(i);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]++;
        arr[b][a]++;
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            sum+=arr[i][j];
        }
        if(sum%2)
            res++;
    }
    if(res!=0 && res!=2)
    {
        cout<<"NO";
        return 0;
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}