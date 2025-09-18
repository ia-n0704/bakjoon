# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[300010];
const ll num=2520;
void sol()
{
    ll sum=0;
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(n==1)
    {
        cout<<sum<<'\n';
        return;
    }
    while(k)
    {
        ll st,en,mx=-1;
        for(int j=1;j<=n;j++)
        {
            int cnt=1;
            ll temp=0;
            for(int r=j-1;r>=max(1ll,j-k);r--)
            {
                temp+=arr[r]-arr[j];
                if((num*temp)/cnt>mx)
                {
                    st=j;
                    en=r;
                    mx=num/cnt*temp;
                }
                cnt++;
            }
            cnt=1;
            temp=0;
            for(int r=j+1;r<=min(n,j+k);r++)
            {
                temp+=arr[r]-arr[j];
                if((num*temp)/cnt>mx)
                {
                    st=j;
                    en=r;
                    mx=num/cnt*temp;
                }
                cnt++;
            }
        }
        cout<<st<<" "<<en<<" "<<mx<<' ';
        k-=max(en-st,st-en);
        if(st<en)
        {
            for(int j=st+1;j<=en;j++)
            {
                sum-=(arr[j]-arr[st]);
                arr[j]=arr[st];
            }            
        }
        else
        {
            for(int j=st-1;j>=en;j--)
            {
                sum-=(arr[j]-arr[st]);
                arr[j]=arr[st];
            }     
        }
        cout<<sum<<'\n';
    }
    cout<<sum<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}