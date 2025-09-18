# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll n,q;
ll arr[200010],brr[200010];
pll tarr[200010],tbrr[200010];
const ll mod=998244353;
void sol()
{
    map<ll,ll> idx_a,reidx_a,idx_b,reidx_b;
    map<ll,pll> m_a,m_b;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        tarr[i]={arr[i],i};
    }
    sort(tarr+1,tarr+n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>brr[i];
        tbrr[i]={brr[i],i};
    }
    sort(tbrr+1,tbrr+n+1);
    for(int i=1;i<=n;i++)
    {
        arr[i]=tarr[i].fi;
        brr[i]=tbrr[i].fi;
        idx_a[tarr[i].se]=i;
        reidx_a[i]=tarr[i].se;
        idx_b[tbrr[i].se]=i;
        reidx_b[i]=tbrr[i].se;
    }
    ll res=1;
    for(int i=1;i<=n;i++)
    {
        res*=min(arr[i],brr[i]);
        res%=mod;
    }
    cout<<res<<' ';
    for(int i=1;i<=n;i++)
    {
        if(m_a[arr[i]].fi==0) m_a[arr[i]].fi=i;
        m_a[arr[i]].se=i;
        if(m_b[brr[i]].fi==0) m_b[brr[i]].fi=i;
        m_b[brr[i]].se=i;
    }
    
    for(int i=1;i<=q;i++)
    {
        ll c,x;
        cin>>c>>x;
        if(c==1)
        {
            ll t=idx_a[x];
            
            ll temp=arr[t];
            swap(idx_a[x],idx_a[reidx_a[m_a[temp].se]]);
            swap(reidx_a[idx_a[x]],reidx_a[idx_a[reidx_a[m_a[temp].se]]]);
            
            arr[m_a[temp].se]++;
            m_a[temp].se--;
            m_a[temp+1].fi=m_a[temp].se+1;
            m_a[temp+1].se=max(m_a[temp+1].se,m_a[temp+1].fi);
            res/=min(temp,brr[m_a[temp].fi]);
            res*=min(temp+1,brr[m_a[temp].fi]);
            res%=mod;
        }
        else
        {
            ll t=idx_b[x];
            
            ll temp=brr[t];
            swap(idx_b[x],idx_b[reidx_b[m_b[temp].se]]);
            swap(reidx_b[idx_b[x]],reidx_b[idx_b[reidx_b[m_b[temp].se]]]);

            brr[m_b[temp].se]++;
            m_b[temp].se--;
            m_b[temp+1].fi=m_b[temp].se+1;
            m_b[temp+1].se=max(m_b[temp+1].se,m_b[temp+1].fi);
            res/=min(temp,arr[m_b[temp].fi]);
            cout<<res<<" ";
            res*=min(temp+1,arr[m_b[temp].fi]);
            cout<<res<<'\n';
            res%=mod;
        }
        cout<<res<<' ';
    }
    cout<<'\n';
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