# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
int n,m;
pll arr[1010];
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;i++)
            cin>>arr[i].first>>arr[i].second;
        sort(arr+1,arr+m+1);
        reverse(arr+1,arr+m+1);
        ll num=n;
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            num=min(num,arr[i].second);
            if(num>=arr[i].first && arr[i].second>=num)
            {
                num--;
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
}