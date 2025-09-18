# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t,n,m;
string s[100];
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>s[i];
        int mnx=100,mxx=0,mny=100,mxy=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='#')
                {
                    mnx=min(mnx,i);
                    mxx=max(mxx,i);
                    mny=min(mny,j);
                    mxy=max(mxy,j);
                }
            }
        }
        if(mxx-mnx!=mxy-mny || mnx==100)
        {
            cout<<0<<'\n';
            continue;
        }
        int tmnx=100,tmxx=0,tmny=100,tmxy=0;
        for(int i=mnx;i<=mxx;i++)
        {
            for(int j=mny;j<=mxy;j++)
            {
                if(s[i][j]=='.')
                {
                    tmnx=min(tmnx,i);
                    tmxx=max(tmxx,i);
                    tmny=min(tmny,j);
                    tmxy=max(tmxy,j);
                }
            }
        }
        if(tmxx-tmnx!=tmxy-tmny || tmnx==100)
        {
            cout<<0<<'\n';
            continue;
        }
        if(!((tmnx==mnx && tmny==mny) || (tmnx==mnx && tmxy==mxy) || (tmxx==mxx && tmny==mny) || (tmxx==mxx && tmxy==mxy)))
        {
            cout<<0<<'\n';
            continue;
        }
        int flag=0;
        for(int i=tmnx;i<=tmxx;i++)
        {
            for(int j=tmny;j<=tmxy;j++)
            {
                if(s[i][j]=='#') flag=1;
            }
        }
        if(flag) cout<<0<<'\n';
        else cout<<1<<'\n';
    }
}