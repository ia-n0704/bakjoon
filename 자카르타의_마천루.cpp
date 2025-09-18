//solved by me
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define inf 1e9
int n,m;
int st,en;
int d[30010];
vector<int> v[30010];
void go()
{
    fill(d,d+n+1,inf);
    d[st]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        pair<int,int> a=pq.top();
        int current=a.second;
        int distance=-a.first;
        //cout<<"| "<<current<<" "<<distance<<'\n';
        pq.pop();
        if(d[current]<distance) continue;
        for(auto j:v[current])
        {
            int num=1;
            while(1)
            {
                int temp=current+j*num;
                //cout<<d[current];
                if(temp>=n) break;
                if(distance+num<d[temp])
                {
                    d[temp]=distance+num;
                    pq.push({-d[temp],temp});
                    if(v[temp].size())
                    {
                        int idx=upper_bound(v[temp].begin(),v[temp].end(),j)-v[temp].begin();
                        if(v[temp][idx-1]==j) break;                        
                    }
                }
                num++;
            }
            num=1;
            while(1)
            {
                int temp=current-j*num;
                if(temp<0) break;
                if(distance+num<d[temp])
                {
                    d[temp]=distance+num;
                    pq.push({-d[temp],temp});
                    if(v[temp].size())
                    {
                        int idx=upper_bound(v[temp].begin(),v[temp].end(),j)-v[temp].begin();
                        if(v[temp][idx-1]==j) break;
                    }
                }
                num++;
            }
        }
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(i==0) st=a;
        else if(i==1) en=a;
        v[a].push_back(b);
    }
    for(int i=0;i<n;i++)
        sort(v[i].begin(),v[i].end());
    go();
    if(d[en]==inf) cout<<-1;
    else cout<<d[en];
}





//solved by seungchan
/*#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30005;

int N, M, dp[MAXN], S, T;
vector<int> P[MAXN];

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int Bi, Pi;
        cin >> Bi >> Pi;
        if(i == 0) S = Bi;
        if(i == 1) T = Bi;
        P[Bi].push_back(Pi);
    }

    for(int i = 0; i < N; i++) {
        sort(P[i].begin(), P[i].end());
        P[i].erase(unique(P[i].begin(),P[i].end()),P[i].end());
    }

    memset(dp, 0x7F, sizeof(dp));

    priority_queue<pair<int, int>> pq;
    dp[S] = 0;
    pq.emplace(0, S);

    while(!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        dist = -dist;
        if(dp[u] < dist) continue;
        for(auto p : P[u]) {
            for(int i = 1; ; i++) {
                int v = u + p * i;
                if(v > N) break;

                if(dist + i < dp[v]) {
                    dp[v] = dist + i;
                    pq.emplace(-dp[v], v);
                }
                if(binary_search(P[v].begin(), P[v].end(), p)) break;
            }

            for(int i = 1; ; i++) {
                int v = u - p * i;
                if(v < 0) break;

                if(dist + i < dp[v]) {
                    dp[v] = dist + i;
                    pq.emplace(-dp[v], v);
                }
                if(binary_search(P[v].begin(), P[v].end(), p)) break;
            }
        }
    }

    if(dp[T] >= 0x7F000000) cout << -1;
    else cout << dp[T];
}*/