# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll two[50];
ll f(int a)
{
    int t=1,cnt=0;
    while(a)
    {
        a-=t;
        if(t*2>a)
            t=1;
        else t*=2;
        cnt++;
    }
    return cnt;
}
ll go(int st,int en)
{
    if(st==en) return f(st);
    if(st+1==en) return max(f(st),f(en));
    int num=0;
    for(int i=0;i<31;i++)
    {
        num=i;
        if(two[i]>en) break;
    }
    if(two[num-1]>=st)
    {
        if(two[num-2]>=st)
            return max(go(0,two[num-2])+num-2,go(0,en-two[num-1])+num-1);
        else if(two[num-1]==st)
            return go(0,en-two[num-1])+num-1;
        else
            return max(go(st-two[num-2],two[num-2])+num-2,go(0,en-two[num-1])+num-1);
    }   
    else 
        return go(st-two[num-1],en-two[num-1])+num-1;
}
int main()
{
    fastio;
    int t;
    cin>>t;
    for(int i=1;i<31;i++)
        two[i]=pow(2,i)-1;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<go(a,b)<<'\n';
    }
}