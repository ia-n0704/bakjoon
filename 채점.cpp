//#1 최적화된 브루트포스 - MLE+TLE..
/*# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
struct T
{
    int num;
    int idx;
    int b;
};
int n;
int arr[200];
int sum[200];
int k;
int ch[573801][2];
int resch[573801];
queue<T> q;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    cin>>k;
    q.push({0,1,0});
    int mx=0;
    while(!q.empty())
    {
        T a=q.front();
        //cout<<a.num<<" "<<a.idx<<" "<<a.b<<'\n';
        q.pop();
        mx=max(mx,a.num);
        resch[a.num]=1;
        if(a.idx>n)
            continue;
        T temp;
        temp.num=a.num+sum[a.idx]-sum[a.b];
        temp.idx=a.idx+1;
        temp.b=a.b;
        ch[temp.num][temp.b]=temp.idx;
        q.push(temp);
        temp.num=a.num;
        temp.idx=a.idx+1;
        temp.b=a.idx;
        if(ch[temp.num][temp.b]!=temp.idx)
        {
            ch[temp.num][temp.b]=temp.idx;
            q.push(temp);
        }
    }
    int i=k;
    //for(int i=0;i<=k;i++)
        //cout<<i<<" "<<resch[i]<<'\n';
    while(1)
    {
        if(resch[i]==0)
        {
            cout<<i;
            return 0;
        }
        i++;
    }
}*/

//#2 dp - bitset 활용
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
ll arr[200];
ll sum[200][200];
ll s[200];
bitset<2000000> dp[200];
ll k;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>arr[i];
        s[i]=s[i-1]+arr[i];
    }
    cin>>k;
    for(int i=1;i<=n;i++) 
    {
        for(int j=i;j<=n;j++)
            sum[i][j]=sum[i][j-1]+s[j]-s[i-1];
    }    
    if(k>sum[1][n])
    {
        cout<<k;
        return 0;
    }
    dp[0].set(0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            if(j<=2)
                dp[i].set(sum[j][i]);
            else dp[i]|=(dp[j-2]<<sum[j][i]);
        }
    }
    ll i=k;
    while(1)
    {
        if(dp[n].test(i)==0)
        {
            cout<<i;
            break;
        }
        i++;
    }
    
}