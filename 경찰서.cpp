#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll finish[100010];
ll ch[100010];
ll scc[100010];
ll arr[100010];
vector <ll> v[100010],v2[100010];
ll num;
stack <ll> s;
ll scc_count;
ll SCC(ll a)
{
    ch[a]=++num;
    ll p=num;
    s.push(a);
    for(ll i=0;i<v[a].size();i++)
    {
        ll b=v[a][i];
        if(ch[b]==0) p=min(p,SCC(b));
        else if(finish[b]==0) p=min(p,ch[b]);
    }

    if(p==ch[a])
    {
        scc_count++;
        while(1)
        {

            ll temp=s.top();
            //prllf("%d | %d\n",temp,scc_count);
            finish[temp]=1;
            s.pop();
            scc[temp]=scc_count;
            if(temp==a)
                break;
        }
    }

    return p;
}
vector<ll> res;
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll a;
            scanf("%1d",&a);
            if(a) v[i].push_back(j);
        }
    }
    for(ll i=1;i<=n;i++)
        if(ch[i]==0) SCC(i);
    for(ll i=1;i<=n;i++)
        v2[scc[i]].push_back(arr[i]);
    ll res=0;
    for(ll i=1;i<=scc_count;i++)
    {
        sort(v2[i].begin(),v2[i].end());
        res+=v2[i][0];
    }
    cout<<res;
}