# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
ll w;
pair<pll,ll> arr[500010];
bool compare(pair<pll,int> a,pair<pll,int> b)
{
    return a.first.first*b.first.second<b.first.first*a.first.second;
}
int main()
{
    fastio;
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first.first>>arr[i].first.second;
        arr[i].second=i;
    }
    sort(arr+1,arr+n+1,compare);
    priority_queue<pll> pq,ans;
    queue<pll> idx;
    ll sum=0;
    ll mxcnt=-1;
    double mx=1e16;
    for(int i=1;i<=n;i++)
    {
        //cout<<"| "<<arr[i].first<<' '<<arr[i].second<<'\n';
        sum+=arr[i].first.second;
        pq.push({arr[i].first.second,arr[i].second});
        idx.push({arr[i].first.second,arr[i].second});
        //cout<<arr[i].first*sum<<" "<<w*arr[i].second<<'\n';
        while(!pq.empty() && arr[i].first.first*sum>w*arr[i].first.second)
        {
            //cout<<"| "<<i<<'\n';
            sum-=pq.top().first;
            pq.pop();
            idx.push({0,0});
        }
        //printf("%lf %lf\n",mx*arr[i].second,(double)arr[i].first*sum);
        if((int)pq.size()>mxcnt || ((int)pq.size()==mxcnt && (double)(mx*arr[i].first.second)>(double)arr[i].first.first*sum))
        {
            mxcnt=(int)pq.size();
            mx=(double)sum*arr[i].first.first/arr[i].first.second;
            
            while(!idx.empty())
            {
                auto a=idx.front(); idx.pop();
                //cout<<a.second<<'\n';
                if(a.first==0)
                {
                    //cout<<ans.top().second<<'\n';
                    ans.pop();
                }
                else ans.push(a);
            }
        }
        //cout<<i<<" "<<pq.size()<<" "<<pq.top().first<<" "<<sum<<" "<<idx.size()<<'\n';
    }
    cout<<ans.size()<<'\n';
    while(!ans.empty())
    {
        cout<<ans.top().second<<'\n';
        ans.pop();
    }
}