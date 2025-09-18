# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int arr[200];
int ch[200];
int num[200];
int mx;
vector<int> res;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        int cur=i;
        vector<int> v;
        while(num[cur]==0)
        {
            v.push_back(cur);
            num[cur]=++cnt;
            cur=arr[cur];
        }
        if(ch[cur]==0)
        {
            for(int i=num[cur];i<=cnt;i++)
                res.push_back(v[i-1]);
        }
        for(auto i:v) ch[i]=1;
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<'\n';
}