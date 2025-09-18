# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
pair<int,int> arr[100010],brr[100010];
int acnty[100010],acntx[100010];
int bcnty[100010],bcntx[100010];
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=m;i++) cin>>brr[i].first>>brr[i].second;
    int stx=100001,sty=100001;
    for(int i=1;i<=n;i++)
    {
        stx=min(stx,arr[i].first);
        sty=min(sty,arr[i].second);
    }
    int flag=0;
    /*for(int i=1;i<=m;i++)
    {
        if(stx>brr[i].first || sty>brr[i].second)
            flag=1;
    }*/
    for(int i=1;i<=n;i++)
    {
        acntx[arr[i].first]++;
        acnty[arr[i].second]++;
    }
    for(int i=1;i<=m;i++)
    {
        bcntx[brr[i].first]++;
        bcnty[brr[i].second]++;
    }
    for(int i=1;i<=100000;i++)
    {
        if(acntx[i]%2!=bcntx[i]%2 || acnty[i]%2!=bcnty[i]%2) flag=1;
    }
    if(flag) cout<<"NO";
    else cout<<"YES";
}