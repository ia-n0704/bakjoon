# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
priority_queue<ll> mn,mx;
ll mxsum,mnsum;
int main()
{
    fastio;
    int n;
    ll sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll a,b;
        cin>>b>>a;
        sum+=abs(b);
        if(mn.size()==mx.size())
        {
            mxsum+=a;
            mx.push(a);
        }
        else
        {
            mnsum+=a;
            mn.push(-a);
        }
        if(!mn.empty() && mx.top()>-mn.top())
        {
            int temp=mx.top();
            int temp2=mn.top();
            mx.pop();
            mn.pop();
            mn.push(-temp);
            mx.push(-temp2);
            mnsum-=-temp2;
            mnsum+=temp;
            mxsum-=temp;
            mxsum+=-temp2;
        }
        cout<<mx.top()<<" ";
        cout<<sum+abs(mxsum-mx.top()*(ll)mx.size())+abs(mx.top()*(ll)mn.size()-mnsum)<<'\n';
    }
}