# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[550][550];
ll arr[550][550];
ll num[550][550];
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void sol()
{
    ll n,m,k;
    ll a=0,b=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    string s[550];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m;j++)
            num[i][j+1]=s[i][j]-'0';
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(num[i][j]) b+=arr[i][j];
            else a+=arr[i][j];
        }
    }
    ll c=abs(a-b);
    if(c==0)
    {
        cout<<"YES\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+num[i][j];
        }
    }
    vector<ll> w;
    k--;
    for(int i=1;i<=n-k;i++)
    {
        for(int j=1;j<=m-k;j++)
        {
            int nx=i+k,ny=j+k;
            ll x=sum[nx][ny]-sum[nx][j-1]-sum[i-1][ny]+sum[i-1][j-1];
            ll y=(k+1)*(k+1)-(sum[nx][ny]-sum[nx][j-1]-sum[i-1][ny]+sum[i-1][j-1]);
            if(x!=y)
                w.push_back(abs(x-y));
        }
    }
    if(w.size()==0)
    {
        cout<<"NO\n";
        return;
    }
    ll g=w[0];
    for(int i=1;i<w.size();i++)
    {
        if(w[i]<=0) continue;
        g=gcd(g,w[i]);
        if(g==1) break;
    }
    if(c%g==0)
        cout<<"YES\n";
    else cout<<"NO\n";
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            sum[i][j]=0;
            num[i][j]=0;
        }
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