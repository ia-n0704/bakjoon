# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sol()
{
    ll n,m;
    cin>>n>>m;
    ll r=n+m;
    ll l=max(0ll,n-m);
    ll num=1;
    ll cnt=0;
    int flag=0;
    ll idx=0;
    if(m==0)
    {
        cout<<n<<'\n';
        return;
    }
    for(ll i=60;i>=0;i--)
    {
        //cout<<i<<" "<<r<<" "<<(ll)(1ll<<i)<<'\n';
        if((r&(ll)(1ll<<i)))
        {
            idx=i;
            if((l&(ll)(1ll<<i)))
                flag=1;
            else flag=0;
            break;
        }
    }
    if(flag)
    {
        ll res=r;
        ll idx2=-1;
        for(ll i=idx-1;i>=0;i--)
        {
            //cout<<r<<" "<<(1ll<<i)<<'\n';
            if((r&(1ll<<i)) && (l&(1ll<<i))==0)
            {
                idx2=i-1;
                break;
            }
        }
        //cout<<" "<<idx2<<'\n';
        for(ll i=idx2;i>=0;i--)
        {
            if((r&(1ll<<i))==0) 
            {
                //cout<<i<<" ";
                res+=(1ll<<i);
            }
        }
        cout<<res<<'\n';
    }
    else 
    {
        ll res=0;
        for(int i=0;i<=idx;i++)
            res+=(ll)pow(2,i);
        cout<<res<<'\n';
    }
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