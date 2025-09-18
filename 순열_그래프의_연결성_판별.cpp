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
vector<int> v[1000010];
int main()
{
    fastio;
    cin>>n;
    int mx=0;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        v[num].push_back(i);
        mx=max(mx,a);
        if(mx==i) num++;
    }
    cout<<num<<'\n';
    for(int i=0;i<num;i++)
    {
        cout<<v[i].size()<<' ';
        for(auto j:v[i])
            cout<<j<<' ';
        cout<<'\n';
    }
}