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
int arr[500010];
int par[500010];
int idx[500010];
int _find(int x)
{
    if(par[x]==x) return x;
    return par[x]=_find(par[x]);
}
void _union(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x==y) return;
    if(x>y) swap(x,y);
    par[y]=x;
}
int par2[500010];
int _find2(int x)
{
    if(par2[x]==x) return x;
    return par2[x]=_find2(par2[x]);
}
void _union2(int x,int y)
{
    x=_find2(x);
    y=_find2(y);
    if(x==y) return;
    if(x<y) swap(x,y);
    par2[y]=x;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        idx[arr[i]]=i;
    }
    for(int i=1;i<=n;i++) par[i]=par2[i]=i;
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty() && (_find2(st.top())==_find(arr[i])-1 || _find(st.top())==_find2(arr[i])+1))
        {
            cout<<idx[st.top()]<<'\n';
            //cout<<_find(st.top())<<" "<<_find(arr[i])<<'\n';
            _union(st.top(),arr[i]);
            _union2(st.top(),arr[i]);
            st.pop();
        }
        st.push(arr[i]);
    }
}