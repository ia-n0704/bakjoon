# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
pll arr[200010];
ll ex,ey;
int main()
{
    fastio;
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr,arr+n);
    vector<ll> x,y;
    for(int i=0;i<n;i++)
    {
        x.push_back(arr[i].first);
        y.push_back(arr[i].second);
    }
    cin>>ex>>ey;
    ll mn=abs(ex)+abs(ey);
    for(int i=0;i<n;i++)
    {
        mn=min(mn,2ll+abs(ex-x[i])+abs(ey-y[i]));
        int idx1=lower_bound(x.begin(),x.end(),ex-x[i]-1)-x.begin();
        int idx2=lower_bound(x.begin(),x.end(),ex-x[i])-x.begin();
        idx2--; 
        if(idx1<=idx2)
        {
            int l=idx1,r=idx2;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(y[mid]>=ey-y[i])
                {
                    r=mid;
                    if(y[mid]==ey-y[i])
                        break;
                }
                else l=mid+1;
            }
            if(r-1>=idx1) mn=min(mn,5ll+abs(ey-y[i]-y[r-1]));
            mn=min(mn,5ll+abs(ey-y[i]-y[r]));            
        }

        idx1=lower_bound(x.begin(),x.end(),ex-x[i])-x.begin();
        idx2=lower_bound(x.begin(),x.end(),ex-x[i]+1)-x.begin();
        idx2--; 
        if(idx1<=idx2)
        {
            int l=idx1,r=idx2;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(y[mid]>=ey-y[i])
                {
                    r=mid;
                    if(y[mid]==ey-y[i])
                        break;
                }
                else l=mid+1;
            }
            mn=min(mn,4ll+abs(ey-y[i]-y[r]));            
        }

        idx1=lower_bound(x.begin(),x.end(),ex-x[i]+1)-x.begin();
        idx2=lower_bound(x.begin(),x.end(),ex-x[i]+2)-x.begin();
        idx2--; 
        if(idx1<=idx2)
        {
            int l=idx1,r=idx2;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(y[mid]>=ey-y[i])
                {
                    r=mid;
                    if(y[mid]==ey-y[i])
                        break;
                }
                else l=mid+1;
            }
            if(r-1>=idx1) mn=min(mn,5ll+abs(ey-y[i]-y[r-1]));
            mn=min(mn,5ll+abs(ey-y[i]-y[r]));            
        }
    }
    if(mn>m) cout<<-1;
    else cout<<mn;
}