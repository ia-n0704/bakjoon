# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int t;
string s[100];
int X[10]={-1,-1,0,0,1,1};
int Y[10]={-1,1,1,-1,-1,1};
int arr[100][100];
struct Bipartite_matching
{
    int N,M;
    vector<int> v[10010];
    int ans[10010];
    int ch[10010];
    void _init(int n,int m)
    {
        N=n;
        M=m;
        fill(ans,ans+M+1,0);
        for(int i=1;i<=N;i++)
            v[i].clear();
        fill(ch,ch+N+1,0);
    }
    void _insert(int a,int b)
    {
        v[a].push_back(b);
        //cout<<a<<" "<<b<<'\n';
    }
    int _go(int x)
    {
        ch[x]=1;
        for(auto i:v[x])
        {
            if(!ans[i])
            {
                ans[i]=x;
                return 1;
            }
            if(!ch[ans[i]] && _go(ans[i]))
            {
                ans[i]=x;
                return 1;
            }
        }
        return 0;
    }
    int _count()
    {
        int res=0;
        for(int i=1;i<=N;i++)
        {
            fill(ch,ch+N+1,0);
            res+=_go(i);
        }
        return res;
    }
};
int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        Bipartite_matching B;
        for(int i=0;i<n;i++) cin>>s[i];
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='.')
                {
                    if(j%2==0) arr[i][j]=++b;
                    else arr[i][j]=++a;
                }
                else arr[i][j]=0;
            }
        }
        B._init(a,b);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j+=2)
            {
                if(arr[i][j]==0) continue;
                for(int k=0;k<6;k++)
                {
                    int nx=i+X[k];
                    int ny=j+Y[k];
                    if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                    if(arr[nx][ny])
                    {
                        //cout<<i<<" "<<j<<" | "<<nx<<" "<<ny<<'\n';
                        B._insert(arr[i][j],arr[nx][ny]);
                    }
                }
            }
        }
        cout<<a+b-B._count()<<'\n';        
    }
}