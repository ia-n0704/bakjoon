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
ll a,b,c,d;
ll arr[100010];
ll res;
int main()
{
    fastio;
    cin>>a>>b>>c>>d;
    if(a-1>b)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=a;i++)
    {
        arr[i]=i-1;
        d-=i-1;
    }
    if(d<0)
    {
        cout<<-1;
        return 0;
    }
    ll num=b;
    for(int i=a;i>=1;i--)
    {
        ll temp=num-arr[i];
        if(temp<=d)
        {
            d-=temp;
            arr[i]=num;
        }
        else
        {
            arr[i]+=d;
            d=0;
        }
        num--;
    }
    if(d!=0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b-arr[i];j++)
            cout<<1<<" ";
        for(int j=1;j<=arr[i];j++)
            cout<<9<<" ";
        cout<<'\n';
    }   
}
