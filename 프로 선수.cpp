# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int arr[200010];
map<int,int> m;
vector<int> dnc(int n)
{
    vector<int> v;
    if(n==1)
    {
        v.push_back(1);
        return v;
    }
    vector<int> s=dnc((n+1)/2),e=dnc(n/2);
    for(auto i:s) v.push_back(2*i-1);
    for(auto i:e) v.push_back(2*i);
    return v;
}
int main()
{
    fastio;
    int n;
    cin>>n;
    /*for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        m[arr[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(m[arr[i]]>=3)
        {
            cout<<-1;
            return 0;
        }
    }*/
    vector<int> res=dnc(n);
    for(auto i:res) cout<<i<<" ";
}