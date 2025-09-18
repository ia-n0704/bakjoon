# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll a,c,d;
ll arr[100010];
ll sum[100010];
ll w[100010];
ll res;
int main()
{
    fastio;
    cin>>a;
    for(int i=1;i<=a;i++)
        cin>>w[i];
    cin>>c>>d;
    for(int i=1;i<=a;i++)
        sum[i]=w[i];
    for(int i=2;i<=a;i++)
    {
        if(sum[i]<=sum[i-1])
        {
            ll num=(sum[i-1]-sum[i])/8+1;
            d-=num;
            if(d<0)
            {
                cout<<-1;
                return 0;
            }
            //cout<<num;
            arr[i]=num;
            sum[i]+=num*8;
            //cout<<i<<" "<<sum[i]<<'\n';
            if(arr[i]>w[i] || sum[i]<=sum[i-1])
            {
                cout<<-1;
                return 0;
            }
        }
    }
    sum[a+1]=1e18;
    for(int i=a;i>=1;i--)
    {
        ll num=(sum[i+1]-sum[i])/8;
        if((sum[i+1]-sum[i])%8==0) num--;
        num=min(num,w[i]-arr[i]);
        //cout<<num<<" ";
        if(num<=0) continue;
        if(num>=d)
        {
            arr[i]+=d;
            d=0;
        }
        else
        {
            arr[i]+=num;
            d-=num;
        }
        //cout<<arr[i]<<"\n";
        sum[i]=arr[i]*9+(w[i]-arr[i]);
    }
    if(d!=0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=arr[i];j++)
            cout<<"9 ";
        for(int j=1;j<=w[i]-arr[i];j++)
            cout<<"1 ";
        cout<<'\n';
    }
}
