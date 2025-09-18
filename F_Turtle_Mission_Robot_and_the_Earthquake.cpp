# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#define mod 998244353
#define inf 1e9
using namespace std;
typedef long long ll;
int arr[1010][1010];
int dp[1010][1010];
int A[5]={-1,0,1};
int B[5]={0,1,0};
void Y()
{
    cout<<"YES\n";
}
void N()
{
    cout<<"NO\n";
}
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    for(int i=0;i<n;i++)
        fill(dp[i],dp[i]+m,inf);
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    while(!q.empty())
    {
        pair<int,pair<int,int>> a=q.front();
        q.pop();
        int num=a.first;
        int fi=a.second.first;
        int se=a.second.second;
        //cout<<num<<" "<<fi<<" "<<se<<'\n';
        dp[fi][se]=min(dp[fi][se],num);
        for(int i=0;i<3;i++)
        {
            int nx=fi+A[i];
            int ny=se+B[i];
            if(nx<0) nx=n-1;
            if(nx==n) nx=0;
            if(ny==m) ny=0;
            //cout<<(nx+num+1)%n<<" "<<ny<<" "<<arr[(nx+num+1)%n][ny]<<'\n';
            if(arr[(nx+num+1)%n][ny])
                continue;
            //if(dp[nx][ny]>num+1)
                q.push({num+1,{nx,ny}});
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        cout<<'\n';
    }
    if(dp[n-1][m-1]==inf)
        cout<<-1<<'\n';
    else cout<<dp[n-1][m-1]<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        sol();
}