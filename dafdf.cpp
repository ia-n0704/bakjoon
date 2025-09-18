# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
vector<pair<int,vector<int>>> ans;
int n;
void sol()
{
    v.clear();
    ans.clear();
    cin>>n;
    for(int i=1;i<=n;i++) v.push_back(i);
    do {
        int mn=n+1;
        int num=0;
        for(int i=1;i<=n;i++)
        {
            mn=n+1;
            for(int j=i;j<=n;j++)
            {
                mn=min(mn,v[j-1]);
                num+=mn;
            }
        }
        ans.push_back({num,v});
    }while(next_permutation(v.begin(),v.end()));
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto i:ans)
    {
        cout<<i.first<<" : ";
        for(auto j:i.second) cout<<j<<" ";
        cout<<'\n';
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