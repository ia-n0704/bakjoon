# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<ll> v;
map<ll,int> m;
ll arr[10]={4,82,50626};
ll brr[10]={1,2,0,3,1,2};
int main()
{
    fastio;
    int t;
    int res=0;
    cin>>t;
    v.push_back(1);
    m[1]=0;
    int cnt=0;
    for(int i=0;i<3;i++)
    {
        v.push_back(arr[i]);
        m[arr[i]]=brr[cnt++];
        v.push_back(arr[i]*arr[i]);
        m[arr[i]*arr[i]]=brr[cnt++];
    }
    v.push_back(1000000000001);
    while(t--)
    {
        ll n;
        cin>>n;
        int idx=upper_bound(v.begin(),v.end(),n)-v.begin();
        idx--;
        //cout<<v[idx]<<" "<<m[v[idx]]<<'\n';
        res^=m[v[idx]];
    }
    if(res)
        cout<<"koosaga";
    else cout<<"cubelover";
}