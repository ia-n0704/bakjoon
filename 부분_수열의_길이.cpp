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
ll x;
ll arr[500010];
ll sum[500010];
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        vector<int> v;
        cin>>n>>x;
        ll mx;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            if(i==1) mx=arr[i];
            sum[i]=sum[i-1]+arr[i];
            if(sum[i]>mx)
            {
                mx=sum[i];
                v.push_back(i);
            }
        }
        int res=n+1;
        int idx=0;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]>=x)
            {
                res=1;
                break;
            }
            int l=idx,r=v.size()-1;
            if(l>r)
                continue;
            while(l<=r)
            {
                int mid=(l+r)/2;
                //cout<<mid<<" "<<v[mid]<<" "<<sum[v[mid]]-sum[i-1]<<'\n';
                if(sum[v[mid]]-sum[i-1]>=x)
                    r=mid-1;
                else l=mid+1;
            }
            //cout<<i<<" "<<v[l]<<'\n';
            if(l<v.size() && sum[v[l]]-sum[i-1]>=x)
                res=min(res,v[l]-i+1);
            if(v[idx]==i)
                idx++;
        }
        if(res==n+1)
            cout<<-1<<'\n';
        else cout<<res<<'\n';
        fill(arr,arr+n+1,0);
        fill(sum,sum+n+1,0);
    }
}