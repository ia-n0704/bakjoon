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
int main()
{
    fastio;
    cin>>n>>q;
    int res=0;
    int l=1,r=2;
    int flag=0;
    int templ,tempr;
    while(q--)
    {
        string s;
        int a;
        cin>>s>>a;
        pair<int,pair<int,int>> resa1,resa2;
        if(s=="R")
        {
            int cnt1=0,cnt2=0;
            templ=l,tempr=r;
            flag=0;
            while(tempr!=a)
            {
                tempr++;
                if(tempr==n+1) tempr=1;
                if(tempr==templ)
                {
                    cnt1++;
                    templ++;
                    flag=1;
                }
                if(templ==n+1) templ=1;
                cnt1++;
            }
            if(flag) cnt1=200;
            resa1={cnt1,{templ,tempr}};
            templ=l,tempr=r;
            flag=0;
            while(tempr!=a)
            {
                tempr--;
                if(tempr==0) tempr=n;
                if(tempr==templ)
                {
                    cnt2++;
                    templ--;
                    flag=1;
                }
                if(templ==0) templ=n;
                cnt2++;
            }
            if(flag) cnt2=200;
            resa2={cnt2,{templ,tempr}};
            if(cnt1>cnt2) swap(resa1,resa2);
        }
        else
        {
            int cnt1=0,cnt2=0;
            templ=l,tempr=r;
            flag=0;
            while(templ!=a)
            {
                templ++;
                if(templ==n+1) templ=1;
                if(templ==tempr)
                {
                    cnt1++;
                    tempr++;
                    flag=1;
                }
                if(tempr==n+1) tempr=1;
                cnt1++;
            }
            if(flag) cnt1=200;
            resa1={cnt1,{templ,tempr}};
            templ=l,tempr=r;
            flag=0;
            while(templ!=a)
            {
                templ--;
                if(templ==0) templ=n;
                if(templ==tempr)
                {
                    cnt2++;
                    tempr--;
                    flag=1;
                }
                if(tempr==0)
                    tempr=n;
                cnt2++;
            }
            if(flag) cnt2=200;
            resa2={cnt2,{templ,tempr}};
            if(cnt1>cnt2) swap(resa1,resa2);
        }
        res+=resa1.first;
        l=resa1.second.first;
        r=resa1.second.second;
        //cout<<res<<" "<<l<<" "<<r<<'\n';
    }
    cout<<res;
}