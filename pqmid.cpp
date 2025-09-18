# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
priority_queue<int> mn,mx;
int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(mn.size()==mx.size())
            mx.push(a);
        else mn.push(-a);
        if(!mn.empty() && mx.top()>-mn.top())
        {
            int temp=mx.top();
            int temp2=mn.top();
            mx.pop();
            mn.pop();
            mn.push(-temp);
            mx.push(-temp2);
        }
        if(i%2) cout<<mx.top()<<'\n';
    }
}