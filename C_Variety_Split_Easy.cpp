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
int arr[300010];
map<int,int> m1,m2;
set<int> s1,s2;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        m1[arr[i]]++;
        s1.insert(arr[i]);
    }    
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        if(m2[arr[i]]==0) s2.insert(arr[i]);
        m2[arr[i]]++;
        m1[arr[i]]--;
        if(m1[arr[i]]==0) s1.erase(arr[i]);
        //cout<<s1.size()<<" "<<s2.size()<<'\n';
        mx=max(mx,(int)s1.size()+(int)s2.size());
    }
    cout<<mx;
}