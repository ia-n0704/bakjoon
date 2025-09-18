# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200010];
ll ansone[200010];
ll anstwo[200010];
ll num[200010];
ll sum[200010];
ll mx[200010];
int ch[200010];
void sol()
{
    ll n,c;
    cin>>n>>c;
    for(int i=0;i<=n+1;i++)
    {
        ansone[i]=0;
        anstwo[i]=0;
        num[i]=0;
        sum[i]=0;
        mx[i]=0;
        ch[i]=0;
    }

    //#ansone implemention
    priority_queue<pair<ll,ll>> pq;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(i==1) arr[i]+=c;
        sum[i]=sum[i-1]+arr[i];
        pq.push({arr[i],-i});
    }
    for(int i=n;i>=1;i--)
        mx[i]=max(mx[i+1],arr[i]);
    int i=0;
    int mex=1;
    while(!pq.empty())
    {
        auto a=pq.top();
        a.second*=-1;
        pq.pop();
        if(ch[a.second]) continue;
        ch[a.second]=1;
        while(ch[mex]) mex++;
        ansone[a.second]=i;
        i++;
        if(mex<=n)
        {
            num[mex]+=a.first;
            pq.push({num[mex],-mex});
        }
    }
    /*for(int i=1;i<=n;i++) cout<<ansone[i]<<" ";
    cout<<'\n';*/

    //#anstwo implemention
    for(int i=1;i<=n;i++)
    {
        if(arr[i]+sum[i-1]>=mx[i])
            anstwo[i]=i-1;
        else anstwo[i]=n+1;
    }
    for(int i=1;i<=n;i++)
        cout<<min(ansone[i],anstwo[i])<<" ";
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