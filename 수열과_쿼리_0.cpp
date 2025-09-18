# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include<bits/stdc++.h>     //수열과 쿼리 4(D-4,13546)
#define MAX 400010
using namespace std;
typedef long long int ll;
struct q
{
    ll idx,s,e;
};
q qer[MAX];
ll ans[MAX];
list<ll> cnt[MAX];
ll dcnt[MAX];
ll sqcnt[MAX];
ll brr[MAX],arr[MAX];
ll sqn;
ll now;
ll lf,rf;
bool sf(q a,q b)
{
    if(a.s/sqn!=b.s/sqn) return a.s<b.s;
    return a.e<b.e;
}
void mib(ll s, ll e)
{
    ll i;
    for(i=e;i>=s;i--)
    {
        ll j=arr[i];
        if(cnt[j].size()>=2)
        {
            ll dis=cnt[j].back()-cnt[j].front();
            dcnt[dis]--;
            sqcnt[dis/448]--;
        }
        cnt[j].pop_back();
        if(cnt[j].size()>=2)
        {
            ll dis=cnt[j].back()-cnt[j].front();
            dcnt[dis]++;
            sqcnt[dis/448]++;
        }
    }
}
void mif(ll s, ll e)
{
    ll i;
    for(i=s;i<=e;i++)
    {
        ll j=arr[i];
        if(cnt[j].size()>=2)
        {
            ll dis=cnt[j].back()-cnt[j].front();
            dcnt[dis]--;
            sqcnt[dis/448]--;
        }
        cnt[j].pop_front();
        if(cnt[j].size()>=2)
        {
            ll dis=cnt[j].back()-cnt[j].front();
            dcnt[dis]++;
            sqcnt[dis/448]++;
        }
    }
}
void plf(ll s, ll e)
{
    ll i;
    for(i=e;i>=s;i--)
    {
        ll j=arr[i];
        if(cnt[j].size()>=2)
        {
            ll dis=cnt[j].back()-cnt[j].front();
            dcnt[dis]--;
            sqcnt[dis/448]--;
        }
        cnt[j].push_front(i);
        ll dis=cnt[j].back()-cnt[j].front();
        dcnt[dis]++;
        sqcnt[dis/448]++;
    }
}
void plb(ll s, ll e)
{
    ll i;
    for(i=s;i<=e;i++)
    {
        ll j=arr[i];
        if(cnt[j].size()>=2)
        {
            ll dis=cnt[j].back()-cnt[j].front();
            dcnt[dis]--;
            sqcnt[dis/448]--;
        }
        cnt[j].push_back(i);
        ll dis=cnt[j].back()-cnt[j].front();
        dcnt[dis]++;
        sqcnt[dis/448]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,j,k,n,Q;
    cin>>n;
    sqn=sqrt(n);
    for(i=1;i<=n;i++)
        cin>>brr[i];
    arr[0]=100000;
    for(i=1;i<=n;i++)
    {
        arr[i]=arr[i-1]+brr[i];
    }
    cin>>Q;
    for(i=1;i<=Q;i++)
    {
        cin>>qer[i].s>>qer[i].e;
        qer[i].idx=i;
        qer[i].s--;
    }
    sort(qer+1,qer+1+Q,sf);
    plf(qer[1].s,qer[1].e);
    for(i=260;i>=0;i--)
    {
        if(sqcnt[i]!=0)
        {
            for(j=447;j>=0;j--)
            {
                if(dcnt[i*448+j]!=0) {
                    now=i*448+j;
                    break;
                }
            }
            break;
        }
    }
    ans[qer[1].idx]=now;
    lf=qer[1].s;
    rf=qer[1].e;
    for(i=2;i<=Q;i++)
    {
        if(qer[i].s<lf) plf(qer[i].s,lf-1);
        if(qer[i].e>rf) plb(rf+1,qer[i].e);
        if(qer[i].s>lf) mif(lf,qer[i].s-1);
        if(qer[i].e<rf) mib(qer[i].e+1,rf);
        lf=qer[i].s;
        rf=qer[i].e;
        for(k=260;k>=0;k--)
        {
            if(sqcnt[k]!=0)
            {
                for(j=447;j>=0;j--)
                {
                    if(dcnt[k*448+j]!=0) {
                        now=k*448+j;
                        break;
                    }
                }
                break;
            }
        }
        ans[qer[i].idx]=now;
    }
    for(i=1;i<=Q;i++)
        cout<<ans[i]<<'\n';
}
