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
int arr[300010];
priority_queue<int> pq[300010];
set<pair<int,int>> s;
set<pair<int,int>> temp;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pq[arr[i]].push(-i);
    }
    for(int i=1;i<=n;i++)
    {
        if(!pq[i].empty()) 
        {
            temp.insert({-pq[i].top(),i});
            s.insert({-pq[i].size(),i});
        }
    }
        
    int num=n/2;
    if(n%2) num++;
    if(-s.begin()->first>num)
    {
        cout<<-1;
        return 0;
    }
    pair<int,int> cmp;
    for(int i=1;i<=n;i++)
    {
        int num=(n-i+1)/2+1;
        auto a=*s.begin();
        if(-a.first>=num)
        {
            cout<<-pq[a.second].top()<<' ';
            s.erase({a.first,a.second});
            temp.erase({-pq[a.second].top(),a.second});
            pq[a.second].pop();
            if(-a.first>1) 
            {
                temp.insert({-pq[a.second].top(),a.second});
                s.insert({a.first+1,a.second});
            }
            cmp=a;
        }
        else
        {
            auto iter=temp.begin();
            while(iter->second==cmp.second && iter!=temp.end()) iter++; 
            auto b=*iter;
            cout<<b.first<<' ';
            int cnt=pq[b.second].size();
            s.erase({-cnt,b.second});
            temp.erase({b.first,b.second});
            pq[b.second].pop(); 
            if(cnt>1) 
            {
                temp.insert({-pq[b.second].top(),b.second});
                s.insert({-(cnt-1),b.second});
            }
            cmp=b;
        }
    }
}
