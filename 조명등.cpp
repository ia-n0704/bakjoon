# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
int n;
ll arr[100010],brr[100010];
ll hx[100010],hy[100010];
string T[5]={".00",".25",".50",".75"};
int sz;
vector<ll> dp;
double cross(int a,int b)
{
    return (double)(arr[a]-brr[a]+arr[b]+brr[b])/2.0;
}
double f(int x,int y)
{
    return (double)(hy[y]-hy[x])/(hx[x]-hx[y]);
}
void insert(ll a,ll b)
{
    hx[sz]=a;
    hy[sz]=b;
    while(sz>1 && f(sz-2,sz-1)>f(sz-1,sz))
    {
        hx[sz-1]=hx[sz];
        hy[sz-1]=hy[sz];
        sz--;
    }
    sz++;
}
ll query(ll x)
{
    int l=0,r=sz-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(f(mid,mid+1)<=x)
            l=mid+1;
        else r=mid;
    }
    return x*hx[l]+hy[l];
}
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i]>>brr[i];
        stack<int> s;
        s.push(0);
        for(int j=1;j<n;j++)
        {
            int i=s.top();
            double num=cross(i,j);
            if(num<=arr[i])
                continue;
            while(num>=arr[j])
            {
                s.pop();
                if(s.empty()) break;
                num=cross(s.top(),j);
            }
            s.push(j);
        }
        n=s.size();
        vector<ll> v1,v2;
        while(!s.empty())
        {
            v1.push_back(arr[s.top()]);
            v2.push_back(brr[s.top()]);
            s.pop();
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        dp.resize(n+1);
        insert(-2*(v1[0]-v2[0]),(v1[0]-v2[0])*(v1[0]-v2[0]));
        for(int i=0;i<n;i++)
        {
            ll X=v1[i]+v2[i];
            ll Y=v1[i+1]-v2[i+1];
            //cout<<X<<'\n';
            dp[i]=query(X)+X*X;
            insert(-2*Y,dp[i]+Y*Y);
        }
        //printf("%lld\n",dp[0]);
        cout<<dp[n-1]/4<<T[dp[n-1]%4]<<'\n';
        dp.clear();
        fill(hx,hx+n+1,0);
        fill(hy,hy+n+1,0);
        sz=0;
    }
}