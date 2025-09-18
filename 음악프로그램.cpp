# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,m;
vector<int> v1[110];
vector<int> v2[1010];
int cnt[1010];
int ch[1010];
int num[1010];
vector<int> ans;
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        for(int j=0;j<a;j++)
        {
            int b;
            cin>>b;
            v1[i].push_back(b);
            v2[b].push_back(i);
            cnt[b]++;
        }
    }
    queue<int> q;
    for(int i=0;i<m;i++)
        cnt[v1[i][0]]--;
    for(int i=1;i<=n;i++)
        if(cnt[i]==0) q.push(i);
    while(!q.empty())
    {
        int a=q.front();
        //cout<<a<<'\n';
        q.pop();
        ch[a]=1;
        ans.push_back(a);
        for(auto i:v2[a])
        {
            if(num[i]!=v1[i].size()-1)
                cnt[v1[i][++num[i]]]--; 
            //cout<<v1[i][num[i]]<<" "<<cnt[v1[i][num[i]]]<<'\n';
            if(cnt[v1[i][num[i]]]==0)
            {
                if(ch[v1[i][num[i]]]==0)
                {
                    q.push(v1[i][num[i]]); 
                }
            }
        }
    }
    if(ans.size()!=n) cout<<0;
    else 
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<'\n';
}