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
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i]=b;
    }
    stack<int> st;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty() && st.top()>arr[i]) st.pop();
        if(st.empty() || st.top()!=arr[i]) st.push(arr[i]);
        else cnt++;
    }
    cout<<n-cnt;
}