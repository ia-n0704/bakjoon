# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll arr[50];
ll num[15][15];
ll sum;
int main()
{
    fastio;
    ll t=6;
    int n;
    //while(scanf("%d",&n)!=EOF)
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n*(n-1)/2;i++) cin>>arr[i];
        sort(arr+1,arr+n*(n-1)/2+1);
        ll x=1,y=2;
        sum=0;
        for(int i=1;i<=n*(n-1)/2;i++)
        {
            sum+=arr[i];
            cout<<x<<" "<<y<<" "<<arr[i]<<'\n';
            num[x][y]=arr[i];
            num[y][x]=arr[i];
            y++;
            if(y>n)
            {
                x++;
                y=x+1;
            }
        }
        if(sum%(n-1))
        {
            cout<<"Impossible\n";
            continue;
        }
        sum/=(n-1);
        sum*=2;
        for(int i=1;i<=n;i++)
        {
            ll temp=sum;
            ll x=1,y=2;
            for(int j=1;j<=n-1;j++)
            {
                if(x==i) x++;
                if(y==i) y++;
                if(x==y) y++;
                if(y>n) y=1;
                if(y==i) y++;
                cout<<x<<" "<<y<<' ';
                temp-=num[x][y];
                cout<<temp<<'\n';
                x++,y++;
            }
            cout<<temp/2<<'\n';
        }
        cout<<'\n';
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                num[i][j]=0;
        }
    }
}