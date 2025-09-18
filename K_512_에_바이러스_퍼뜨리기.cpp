# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,q;
int ch[200010];
int main()
{
    fastio;
    cin>>n>>q;
    int cnt=n;
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a;
        if(a==3)
            cout<<cnt<<'\n';
        else
        {
            cin>>b;
            if(a==1)
            {
                if(ch[b]==0)
                    cnt--;
                ch[b]=1;
            }
            else
            {
                if(ch[b]==1)
                    cnt++;
                ch[b]=0;
            }
        }
    }
}