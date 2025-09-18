# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
int arr[1<<8][1<<8];

void dnc(int stx,int sty,int enx,int eny)
{
    int flag=arr[stx][sty],temp=0;
    for(int i=stx;i<=enx;i++)
    {
        for(int j=sty;j<=eny;j++)
            if(arr[i][j]!=flag) temp=1;
    }
    if(temp)
    {
        cout<<"(";
        int midx=(stx+enx)/2;
        int midy=(sty+eny)/2;
        dnc(stx,sty,midx,midy);
        dnc(stx,midy+1,midx,eny);
        dnc(midx+1,sty,enx,midy);
        dnc(midx+1,midy+1,enx,eny);
        cout<<")";
    }
    else cout<<flag;
}
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>arr[i][j];
    dnc(1,1,n,n);
}