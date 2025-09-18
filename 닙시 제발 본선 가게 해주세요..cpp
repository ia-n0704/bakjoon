//저 진짜 간절하게 닙씨 본선 가보고 싶어요.. 제발 붙게 해주세요 제발..

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll n;
pair<pair<ll,ll>,ll> arr[200010],brr[200010];
vector<pair<ll,ll>> ans,ans2;
ll ch[200010];
pll st={0,0};
ll res;
ll dist(pll a,pll b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}
bool compare(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b)
{
    if(dist(a.first,st)<dist(b.first,st)) return true;
    else return false;
}
void dfs(ll cnt,ll a)
{
    if(cnt==n)
    {
        if(res<a)
        {
            while(ans.size()) ans.pop_back();
            for(auto i:ans2) ans.push_back(i);
            res=a;
        }
        
        return;
    }
    ll num;
    for(ll j=1;j<=n;j++)
    {
        if(ch[j]==0)
        {
            num=j;
            for(ll i=1;i<=n;i++)
            {
                if(ch[i]) continue;
                ch[num]=1;
                ch[i]=1;
                ans2.push_back({num,i});
                dfs(cnt+2,a+dist(arr[num].first,arr[i].first));
                ans2.pop_back();
                ch[i]=0;
                ch[num]=0;
            }     
            break;   
        }
    }

}
int main()
{
    fastio;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i].first.first>>arr[i].first.second;
        arr[i].second=i;
        st.first=min(st.first,arr[i].first.first);
        st.second=min(st.second,arr[i].first.second);
    }
    
    if(n<=16)
        dfs(0,0);
    else
    {
        sort(arr+1,arr+n+1,compare);
        for(ll i=1;i<=n/2;i++)
        {
            ans.push_back({arr[i].second,arr[n-i+1].second});
            res+=dist(arr[i].first,arr[n-i+1].first);
        }
    }
    cout<<res<<'\n';
    for(auto i:ans) cout<<i.first<<" "<<i.second<<'\n';
}