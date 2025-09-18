# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m,k;
int ch[400010];
vector<int> v;
int main()
{
    fastio;
    cin>>n>>m>>k;
    swap(n,m);
    int A,B;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        ch[a]=ch[b]=1;
    }
    cin>>A>>B;
    ch[A]=ch[B]=1;
    int num=abs(A%k-B%k);
    for(int i=1;i<=4*m;i++)
    {
        if(ch[i]==0)
            v.push_back(i%k);
    }
    sort(v.rbegin(),v.rend());
    int cnt=0;
    int idx=1;
    for(int i=0;i<v.size();i++)
    {
        //cout<<idx<<" "<<num<<'\n';
        //cout<<v[idx]<<'\n';
        while(idx<v.size() && num>=abs(v[i]-v[idx])) idx++;
        if(idx<v.size() && num<abs(v[i]-v[idx]))
        {
            cnt++;
            idx++;
        }
    }
    cout<<min(n-1,cnt);
}