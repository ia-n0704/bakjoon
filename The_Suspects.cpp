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
int ch[30010];
int main()
{
    fastio;
    while(1)
    {
        cin>>n>>m;
        if(!n && !m) break;
        vector<int> v1[30010],v2[30010];
        for(int i=1;i<=m;i++)
        {
            int a;
            cin>>a;
            for(int j=1;j<=a;j++)
            {
                int b;
                cin>>b;
                v1[b].push_back(i);
                v2[i].push_back(b);
            }
        }
        queue<int> q;
        int cnt=0;
        q.push(0);
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(auto i:v1[a])
            {
                for(auto j:v2[i])
                {
                    if(ch[j]==0)
                    {
                        q.push(j);
                        ch[j]=1;
                        cnt++;
                    }
                }
            }
        }
        if(cnt==0)
            cnt++;
        cout<<cnt<<'\n';
        fill(ch,ch+n+1,0);
    }
}