//try_1 : priority_queue+map으로 해당 인덱스에 대한 [l,r]값 관리
//-> T.L.E
//-> nlogn인데 TLE 간당간당하게 통과될 줄 알았으나 맞.왜.틀

/*# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
ll arr[1000010];
priority_queue<pair<ll,ll>> pq;
map<ll,pair<ll,ll>> m;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pq.push({-arr[i],i});
        m[i]={i,i};
    }
    ll res=0;
    while(pq.size()>1)
    {
        auto a=pq.top();
        a.first*=-1;
        //cout<<a.first<<" "<<a.second<<' ';
        pq.pop();
        ll l=m[a.second].first,r=m[a.second].second;
        //cout<<l<<" "<<r<<'\n';
        ll b;
        if(l==1)
            b=r+1;
        else if(r==n)
            b=l-1;
        else b=arr[l-1]>arr[r+1]?r+1:l-1;
        //cout<<b<<'\n';
        arr[l]=arr[b];
        m[b]={min(m[b].first,l),max(m[b].second,r)};
        res+=ll(arr[b]-a.first);
    }
    cout<<res;
}*/


//try_2 : 스택 활용
//스택의 top보다 큰 수가 나왔을 때 스택을 pop하며 res 갱신
//-> A.c
# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
stack<int> s;
ll res;
int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        int b;
        int cnt=0;
        while(!s.empty() && s.top()<=a)
        {
            if(cnt>0)
                res+=s.top()-b;
            b=s.top();
            s.pop();
            cnt++;
        }
        if(cnt>0) res+=ll(a-b);
        s.push(a);
        //cout<<res<<" ";
    }
    int cnt=0;
    int b;
    while(!s.empty())
    {
        if(cnt>0) res+=s.top()-b;
        b=s.top();
        s.pop();
        cnt++;
    }
    cout<<res;
}