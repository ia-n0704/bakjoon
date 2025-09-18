# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,m;
int u,v;
string arr[202];
int main()
{
    fastio;
    cin>>n>>m>>u>>v;
    for(int i=1;i<=u;i++)
        cin>>arr[i];
    char s[500];
    scanf("%s",s);
    string a=string(s);
    if(a=="clamp-to-edge")
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<arr[min(i,u)][min(j,v)];
            cout<<'\n';
        }        
    }
    else if(a=="repeat")
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<arr[(i-1)%u+1][(j-1)%v+1];
            cout<<'\n';
        }   
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int nx=(i-1)%u+1;
                if((i-1)/u%2) nx=u-nx+1;
                int ny=(j-1)%v+1;
                if((j-1)/v%2) ny=v-ny+1;
                cout<<arr[nx][ny];
            }
            cout<<'\n';
        }   
    }
}
