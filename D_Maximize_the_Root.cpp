# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[200010],ch[200010];
vector<int> v[200010];
void dfs(int x)
{
    ch[x]=1;
    ll mn=(ll)1e16;
    for(auto i:v[x])
    {
        if(ch[i]==0)
        {
            dfs(i);
            mn=min(mn,arr[i]);
        }
    }
    if(mn!=(ll)1e16)
    {
        if(x==1) arr[x]+=mn;
        else if(arr[x]<mn) arr[x]=(arr[x]+mn)/2;
        else arr[x]=mn;
    }
}
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int j=2;j<=n;j++)
    {
        int p;
        cin>>p;
        v[p].push_back(j);
    } 
    dfs(1);
    cout<<arr[1]<<'\n';
    fill(ch,ch+n+1,0);
    for(int i=1;i<=n;i++)
        v[i].clear();
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}