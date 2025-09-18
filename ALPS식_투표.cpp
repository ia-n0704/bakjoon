# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int x;
int n;
map<string,int> ans;
struct staff
{
    string name;
    int flag;
    int num;
    int arr[20];
    int cnt=1;
}s[15];
int main()
{
    fastio;
    cin>>x>>n;
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].name>>s[i].num;
        if(s[i].num*20>=x) s[i].flag=1;
        else s[i].flag=0;
        for(int j=1;j<=14;j++)
            s[i].arr[j]=s[i].num/j;
        if(s[i].flag)
            pq.push({s[i].arr[1],i});
    }
    for(int i=1;i<=14;i++)
    {
        if(!pq.empty())
        {
            auto a=pq.top(); pq.pop();
            ans[s[a.second].name]++;
            s[a.second].cnt++;
            pq.push({s[a.second].arr[s[a.second].cnt],a.second});
        }
    }
    vector<pair<string,int>> v;
    for(int i=1;i<=14;i++)
    {
        if(s[i].flag)
        {
            v.push_back({s[i].name,ans[s[i].name]});
        }
    }
    sort(v.begin(),v.end());
    for(auto i:v)
        cout<<i.first<<" "<<i.second<<'\n';
}