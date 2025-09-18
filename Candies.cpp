//try_1 : 구현 이슈로 wa. retry ㄱㄱ

/*# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e18;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll arr[200010];
int n;
int ch[200010];
ll sum[200010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sum[1]=arr[1];
    for(int i=2;i<=n;i++) 
        sum[i]=sum[i-2]+arr[i];
    priority_queue<pair<ll,pair<ll,ll>>> pq_two;
    priority_queue<pair<ll,ll>> pq_one;
    set<pair<ll,ll>> s,s2;
    for(int i=1;i<=n;i++) pq_one.push({arr[i],i});
    ll res=0;
    for(int i=1;i<=n/2+n%2;i++)
    {
        pair<ll,ll> a={-inf,-inf};
        while(!pq_one.empty() && ch[pq_one.top().second]) pq_one.pop();
        if(!pq_one.empty()) a=pq_one.top();
        pair<ll,pair<ll,ll>> b={-inf,{-inf,-inf}};
        while(!pq_two.empty() && s2.count(pq_two.top().second)) pq_two.pop();
        if(!pq_two.empty()) b=pq_two.top();
        ll temp;
        cout<<a.first<<" "<<a.second<<" | "<<b.first<<" "<<b.second.first<<" "<<b.second.second<<'\n';
        if(a.first>=b.first)
        {
            res+=a.first;
            ch[a.second]=1;
            ll l=a.second,r=a.second;
            if(l>1) l--;
            if(r<n) r++;
            auto idx=s.lower_bound({r,0});
            if(idx!=s.end())
            {
                //cout<<"-> "<<(*idx).first<<" "<<(*idx).second<<'\n';
                temp=(*idx).first;
                if(temp==r)
                {
                    r=(*idx).second;
                    s2.insert(*idx);
                    s.erase(idx);
                }                
            }
            if(idx!=s.begin())
                idx--;
            temp=(*idx).second;
            if(temp==l)
            {
                l=(*idx).first;
                s2.insert(*idx);
                s.erase(idx);
            }
            s.insert({l,r});
            ll num;
            if(r==n && r%2!=l%2)
            {
                num=sum[r-1]-sum[r];
                if(l>1) num+=sum[l-1]-sum[l-2];
            }
            else
            {
                num=sum[r]-sum[r-1];
                if(l>1) num+=sum[l-1]-sum[l-2];                
            }
            pq_two.push({num,{l,r}});
            ch[l]=1;
            ch[r]=1;
        }
        else
        {
            pq_two.pop();
            ll l=b.second.first,r=b.second.second;
            if(l>1) l--;
            if(r<n) r++;
            auto idx=s.lower_bound({r,0});
            if(idx!=s.end())
            {
                temp=(*idx).first;
                if(temp==r)
                {
                    r=(*idx).second;
                    s2.insert(*idx);
                    s.erase(idx);
                }                
            }
            if(idx!=s.begin())
                idx--;
            temp=(*idx).second;
            if(temp==l)
            {
                l=(*idx).first;
                s2.insert(*idx);
                s.erase(idx);
            }
            res+=b.first;
            s.insert({l,r});
            ll num;
            if(r==n && l%2!=r%2)
            {
                num=sum[r-1]-sum[r];
                if(l>1) num+=sum[l-1]-sum[l-2];
            }
            else
            {
                num=sum[r]-sum[r-1];
                if(l>1) num+=sum[l-1]-sum[l-2];
            }
            pq_two.push({num,{l,r}});
            ch[l]=1;
            ch[r]=1;
        }
        cout<<res<<'\n';
    }
}*/


//try_2 : 더 간단하게 pq 하나로 구현 ㄱㄱ

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
const ll inf=1e18;
struct Candy
{
    ll num,l,r,ch=0;
};
Candy arr[200010];
priority_queue<pair<ll,ll>> pq;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].num;
        pq.push({arr[i].num,i});
        arr[i].l=i-1;
        arr[i].r=i+1;
    }
    ll res=0;
    arr[0].num=-inf;
    arr[n+1].num=-inf;
    for(int i=1;i<=n/2+n%2;i++)
    {
        while(!pq.empty() && arr[pq.top().second].ch) pq.pop();
        auto a=pq.top();
        pq.pop();
        arr[arr[a.second].l].ch=1;
        arr[arr[a.second].r].ch=1;
        res+=a.first;
        arr[a.second].num=arr[arr[a.second].l].num+arr[arr[a.second].r].num-arr[a.second].num;
        arr[a.second].l=arr[arr[a.second].l].l;
        arr[arr[a.second].l].r=a.second;
        arr[a.second].r=arr[arr[a.second].r].r;
        arr[arr[a.second].r].l=a.second;
        pq.push({arr[a.second].num,a.second});
        cout<<res<<'\n';
    }
}