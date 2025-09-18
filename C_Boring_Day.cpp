# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200010];
void sol()
{
    ll n,l,r;
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>arr[i];
    queue<ll> q;
    ll s=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        q.push(s);
        s+=arr[i];
        while(!q.empty() && s-q.front()>r) q.pop();
        if(!q.empty() && s-q.front()>=l && s-q.front()<=r)
        {
            //cout<<i<<" "<<s<<" "<<q.front()<<'\n';
            cnt++;
            s=0;
            while(!q.empty()) q.pop();
        }
    }
    cout<<cnt<<'\n';
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