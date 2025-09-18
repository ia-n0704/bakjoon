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
int n;
int arr[5010];
int ch[100010];
int ans[5010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        ch[arr[i]]++;
    }
    vector<pii> v;
    for(int i=1;i<=100000;i++)
        if(ch[i]) v.push_back({ch[i],i});
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    if(v[0].first>n/2)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<v.size();i++)
    {
        int cnt=v[i].first;
        int num=v[i].second;
        for(int j=1;j<=n;j++)
        {
            if(ans[j]==0 && num!=arr[j])
            {
                cnt--;
                ans[j]=num;
            }
            if(cnt<=0) break;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}
