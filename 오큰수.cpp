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
int arr[1000010];
int res[1000010];
stack<pair<int,int>> st;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        while(!st.empty())
        {
            auto a=st.top();
            if(a.first<arr[i])
            {
                res[a.second]=arr[i];
                st.pop();
            }
            else break;
        }
        st.push({arr[i],i});
    }
    for(int i=1;i<=n;i++)
    {
        if(res[i]==0) cout<<-1<<" ";
        else cout<<res[i]<<" ";
    }
}