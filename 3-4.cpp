//이상한 거;;

/*# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[20010];
const int inf=1e9;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr+1,arr+n+1);
    int mxr=-inf,mnr=inf,mnl,mxl;
    int res=inf;
    for(int i=0;i<=n;i++)
    {
        if(i)
        {
            mxr=max(mxr,arr[i].second);
            mnr=min(mnr,arr[i].second);
        }
        int tempmx=mxr,tempmn=mnr;
        for(int j=n+1;j>i;j--)
        {
            tempmx=max(tempmx,arr[i].second);
            tempmn=min(tempmn,arr[i].second);
            if(j==i+1)
                mxl=mnl=0;
            res=min(res,abs(min(mnl,mxl))+abs(mxl-mnl)+abs(min(mnr,mxr))+abs(mxr-mnr));
        }
    }
    cout<<res;
}*/

//제대로.

# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,a,b;
int dp[5][5][2010];
pii arr[20010];
int main()
{
    fastio;
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].fi>>arr[i].se;
        arr[i].fi+=1000;
        arr[i].se+=1000;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<=2000;k++)
            {
                int nx=j%2?arr[i].fi:k,ny=j%2?k:arr[i].se;
                dp[i%2][j][k]=min(dp[(i%2)^1][0][nx]+abs(ny-arr[i+1].se),dp[(i%2)^1][1][ny]+abs(nx-arr[i+1].fi));
            }
        }
    }
    cout<<min(dp[1][0][1000]+abs(arr[1].se-1000),dp[1][1][1000]+abs(arr[1].fi-1000));
}
