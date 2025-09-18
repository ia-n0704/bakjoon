# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e16;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
string s;
ll arr[200010];
ll co[200010];
ll zosum[200010];
ll ozsum[200010];
int main()
{
    fastio;
    cin>>n;
    cin>>s;
    for(int i=1;i<=n;i++)
        arr[i]=s[i-1]-'0';
    for(int i=1;i<=n;i++)
    {
        cin>>co[i];
        zosum[i]=zosum[i-1];
        ozsum[i]=ozsum[i-1];
        if(i%2)
        {
            if(arr[i]==0)
                ozsum[i]+=co[i];
            else zosum[i]+=co[i];
        }
        else
        {
            if(arr[i]==1)
                ozsum[i]+=co[i];
            else zosum[i]+=co[i];
        }
    }
    ll res1=inf,res2=inf;
    for(int i=1;i<n;i++)
    {
        //cout<<zosum[i-1]<<" "<<ozsum[n]-ozsum[i+1]<<'\n';
        ll lnum,rnum;
        if(i%2)
        {
            rnum=ozsum[n]-ozsum[i+1];
            lnum=zosum[i-1];
        }
        else 
        {
            rnum=zosum[n]-zosum[i+1];
            lnum=ozsum[i-1];
        }
        //cout<<lnum<<" "<<rnum<<'\n';
        ll num=lnum+rnum;
        if(arr[i]==1) num+=co[i];
        if(arr[i+1]==1) num+=co[i+1];
        res1=min(res1,num);
    }
    for(int i=1;i<n;i++)
    {
        //cout<<zosum[i-1]<<" "<<ozsum[n]-ozsum[i+1]<<'\n';
        ll lnum,rnum;
        if(i%2==0)
        {
            rnum=ozsum[n]-ozsum[i+1];
            lnum=zosum[i-1];
        }
        else 
        {
            rnum=zosum[n]-zosum[i+1];
            lnum=ozsum[i-1];
        }
        //cout<<lnum<<" "<<rnum<<'\n';
        ll num=lnum+rnum;
        if(arr[i]==0) num+=co[i];
        if(arr[i+1]==0) num+=co[i+1];
        res2=min(res2,num);
    }
    cout<<min(res1,res2);
}