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
pair<int,int> arr[100010];
int main()
{
    fastio;
    int T;
    cin>>T;
    while(T--)
    {
        pair<int,int> p1,p2;
        cin>>n;
        cin>>p1.first>>p1.second;
        cin>>p2.first>>p2.second;
        for(int i=1;i<=n-2;i++)
            cin>>arr[i].first>>arr[i].second;
        sort(arr+1,arr+n-1);
        int idx=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=1;i<=n-2;i++)
        {
            if(min(p1.second,p2.second)<=arr[i].first)
            {
                idx=i;
                break;
            }
        }
        for(int i=1;i<idx;i++)
        {
            if(!pq.empty() && pq.top().first<=arr[i].first)
                pq.pop();
            pq.push({arr[i].second,0});
        }

        if(!pq.empty() && pq.top().first<=p1.first)
            pq.pop();
        pq.push({p1.second,1});

        pair<int,int> temp;
        if(!pq.empty() && pq.top().first<=p2.first)
        {
            if(pq.top().second)
            {
                temp=pq.top();
                pq.pop();
                if(!pq.empty() && pq.top().first<=p2.first)
                    pq.pop();
                pq.push(temp);
            }
            else
                pq.pop();
        }
        pq.push({p2.second,2});

        for(int i=idx;i<=n-2;i++)
        {
            if(pq.top().first<=arr[i].first)
                pq.pop();
            pq.push({arr[i].second,0});
        }
        cout<<pq.size()<<'\n';
    }
}