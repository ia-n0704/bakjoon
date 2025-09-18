#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
ll arr[100010];
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        arr[a]=b;
    }
    for(int i=1;i<=n;i++)
        arr[i]+=arr[i-1];
    while(q--)
    {
        int p;
        cin>>p;
        cout<<min(arr[p],arr[n]-arr[p])<<'\n';
    }
}