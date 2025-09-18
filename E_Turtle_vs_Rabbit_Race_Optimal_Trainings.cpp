# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
ll arr[100010];
ll sum[100010];
void Y()
{
    cout<<"YES\n";
}
void N()
{
    cout<<"NO\n";
}
ll f(ll t,ll num)
{
    ll temp1=t*(t+1)/2;
    if(t>=num)
        return temp1-(t-num)*(t-num+1)/2;
    else
    {
        ll idx=num-t-1;
        ll temp2=idx*(idx+1)/2;
        return temp1-temp2;
    }
}
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(i==0) sum[i]=arr[i];
        else sum[i]=sum[i-1]+arr[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        ll l=a,r=n-1;
        ll res=-1e16;
        ll resl=-1;
        while(l<=r)
        {
            ll mid=(l+r)/2; 
            ll num=0;
            if(a==0) 
                num=sum[mid];
            else num=sum[mid]-sum[a-1];
            //cout<<mid<<" "<<num<<" "<<resl+1<<'\n';
            ll temp=f(b,num);
            //cout<<temp<<'\n';
            if(res<=temp)
            {
                if(res==temp)
                {
                    if(resl>mid)
                        resl=mid;                    
                }
                else resl=mid;
                res=temp;
            }
            res=max(res,temp);
            if(num>b)
                r=mid-1;
            else l=mid+1;
        }
        cout<<resl+1<<" ";
    }
    cout<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        sol();
}