# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
map<pii,int> m;
map<pii,int> front,side,top;
int sz_f,sz_s,sz_t;
void block(int x,int y,int flag)
{
    int z=m[{x,y}];
    if(flag)
    {
        front[{x,z}]++;
        side[{y,z}]++;
        top[{x,y}]++;
        if(front[{x,z}]==1) sz_f++;
        if(side[{y,z}]==1) sz_s++;
        if(top[{x,y}]==1) sz_t++;
    }
    else
    {
        front[{x,z}]--;
        side[{y,z}]--;
        top[{x,y}]--;
        if(front[{x,z}]==0)
            sz_f--;
        if(side[{y,z}]==0)
            sz_s--;
        if(top[{x,y}]==0)  
            sz_t--;
    }
}
int main()
{
    fastio;
    int n,M,q;
    cin>>n>>M>>q;
    while(q--)
    {
        string s;
        int x,y;
        cin>>s;
        if(s=="STACK")
        {
            cin>>x>>y;
            m[{x,y}]++;
            block(x,y,1);
        }
        else if(s=="REMOVE")
        {
            cin>>x>>y;
            if(m[{x,y}]>0)
            {
                block(x,y,0);
                m[{x,y}]--;
            }
        }
        else if(s=="FRONT")
            cout<<sz_f<<'\n';
        else if(s=="SIDE")
            cout<<sz_s<<'\n';
        else cout<<sz_t<<'\n';
    }
}
