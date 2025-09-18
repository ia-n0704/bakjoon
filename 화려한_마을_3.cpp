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
int arr[100010];
int num[200010];
int num2[200010];
int ans[100010];
int sqrtn;
struct Q
{
    int x,y,z;
};
Q query[100010];
bool compare(Q a,Q b)
{
    if(a.x/sqrtn<b.x/sqrtn || (a.x/sqrtn==b.x/sqrtn && a.y<b.y)) return 1;
    else return 0;
}
int main()
{
    fastio;
    cin>>n>>q;
    sqrtn=sqrt(n);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) arr[i]+=100000;
    for(int i=1;i<=q;i++)
    {
        cin>>query[i].x>>query[i].y;
        query[i].z=i;
    }
    sort(query+1,query+q+1,compare);
    int s=query[1].x,e=query[1].y;
    int mxidx=0,mx=0;
    for(int i=s;i<=e;i++)
    {
        num[arr[i]]++;
        num2[num[arr[i]]-1]--;
        num2[num[arr[i]]]++;
        mx=max(mx,num[arr[i]]);
    }
    ans[query[1].z]=mx;
    for(int i=2;i<=q;i++)
    {
        queue<int> q;
        if(query[i].x<s)
        {
            for(int j=query[i].x;j<s;j++)
            {
                num[arr[j]]++;
                num2[num[arr[j]]-1]--;
                num2[num[arr[j]]]++;
                mx=max(mx,num[arr[j]]);
            }
        }
        else
        {
            for(int j=s;j<query[i].x;j++)
            {
                num[arr[j]]--;
                num2[num[arr[j]]]++;
                num2[num[arr[j]]+1]--;
                if(mx==num[arr[j]]+1 && num2[num[arr[j]]+1]==0)
                    mx--;
            }
        }
        if(query[i].y<e)
        {
            for(int j=query[i].y+1;j<=e;j++)
            {
                num[arr[j]]--;
                num2[num[arr[j]]]++;
                num2[num[arr[j]]+1]--;
                if(mx==num[arr[j]]+1 && num2[num[arr[j]]+1]==0)
                    mx--;
            }
        }
        else
        {
            for(int j=e+1;j<=query[i].y;j++)
            {
                num[arr[j]]++;
                num2[num[arr[j]]-1]--;
                num2[num[arr[j]]]++;
                mx=max(mx,num[arr[j]]);
            }
        }
        ans[query[i].z]=mx;
        s=query[i].x;
        e=query[i].y;
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<'\n';
}