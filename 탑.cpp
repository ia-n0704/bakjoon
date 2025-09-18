# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
stack<pii> st;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        while(!st.empty())
        {
            if(st.top().first<a)
                st.pop();
            else break;
        }
        if(st.empty()) cout<<0<<" ";
        else cout<<st.top().second<<' ';
        st.push({a,i});
    }
}