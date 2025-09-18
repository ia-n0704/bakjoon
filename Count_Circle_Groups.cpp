# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct T{
    double x,y,r;
};
int t;
int n;
T arr[3010];
int ch[3010][3010];
int par[3010];
vector<int> v[3010];
double dist(T a,T b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
    fastio;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i].x>>arr[i].y>>arr[i].r;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dist(arr[i],arr[j])<=(arr[i].r+arr[j].r)*(arr[i].r+arr[j].r))
                {
                    ch[i][j]=1;
                    ch[j][i]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            v[i].push_back(i);
            par[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //cout<<i<<" "<<j<<" "<<ch[i][j]<<'\n';
                if(ch[i][j] && par[i]!=par[j])
                {
                    if(v[par[i]].size()>v[par[j]].size())
                    {
                        for(auto t:v[par[j]])
                        {
                            par[t]=par[i];
                            v[par[i]].push_back(t);
                        }
                    }
                    else
                    {
                        for(auto t:v[par[i]])
                        {
                            par[t]=par[j];
                            v[par[j]].push_back(t);
                        }
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(par[i]==i) cnt++;
        cout<<cnt<<'\n';
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) ch[i][j]=0;
        for(int i=0;i<n;i++) v[i].clear();
    }
}