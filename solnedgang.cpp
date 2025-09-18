#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
pair<ll,ll> arr[300010];
ll ch[300010];
void jungsanghwa_time(long long K, std::vector<long long> X, std::vector<long long> Y){
	ll N = ((ll)X.size() + (ll)Y.size()) / 2;
	ll n=N;
    ll k=K;
    for(ll i=0;i<n;i++)
        arr[i+1]={X[i],Y[i]};
    
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> q;
    for(ll i=1;i<=n;i++) ch[i]=-1;
    pair<ll,ll> st=arr[1],en=arr[n];
    ll st_idx,en_idx;
    sort(arr+1,arr+n+1);
    for(ll i=1;i<=n;i++)
    {
        if(arr[i]==st) st_idx=i;
        if(arr[i]==en) en_idx=i;
    }
    q.push({0,arr[st_idx]});
    ch[st_idx]=0;
    while(!q.empty())
    {
        pair<ll,pair<ll,ll>> a=q.top();
        //cout<<a.first<<" "<<a.second.first<<" "<<a.second.second<<'\n';
        q.pop();
        if(arr[en_idx]==a.second)
            continue;
        ll top_idx=lower_bound(arr+1,arr+n+1,a.second)-arr;
        top_idx++;
        ll top=1e18;
        if(top_idx<=n && arr[top_idx].first==a.second.first) top=arr[top_idx].second;
        //cout<<top<<'\n';
        ll idx=lower_bound(arr+2,arr+n+1,make_pair(a.second.first-1,a.second.second+2))-arr;
        for(ll i=idx-1;i<=n;i++)
        {
            if(arr[i].first<a.second.first-1) continue;
            if(arr[i].first>a.second.first-1) break;
            if(arr[i].second>=top-1) break;
            ll num=abs(arr[i].second-a.second.second);
            ll temp=max(0ll,num-a.first);
            if(temp+a.first>=k) continue;
            if(ch[i]==-1 || ch[i]>temp+a.first)
            {
                ch[i]=temp+a.first;
                q.push({a.first+temp,arr[i]});
            }
        }

        idx=lower_bound(arr+2,arr+n+1,make_pair(a.second.first+1,a.second.second+2))-arr;
        for(ll i=idx-1;i<=n;i++)
        {
            if(arr[i].first<a.second.first+1) continue;
            if(arr[i].first>a.second.first+1) break;
            if(arr[i].second>=top-1) break;
            ll num=abs(arr[i].second-a.second.second);
            ll temp=max(0ll,num-a.first);
            if(temp+a.first>=k) continue;
            if(ch[i]==-1 || ch[i]>temp+a.first)
            {
                ch[i]=temp+a.first;
                q.push({a.first+temp,arr[i]});
            }
        }
    }
    if(ch[en_idx]!=-1 && ch[en_idx]<k) cout<<ch[en_idx];
    else cout<<"NATT";
}
int main()
{
    fastio;
    ll n,k;
    vector<ll> a,b;
    cin>>n>>k;
    for(int i=0;i<n;i++) 
    {
        ll x,y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    jungsanghwa_time(k,a,b);
}