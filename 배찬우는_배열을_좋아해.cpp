# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int num[3010];
int arr[3010][3010];
int main()
{
    fastio;
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    for(int i=1;i<=n;i++) num[i]=i;
    for(int i=1;i<=q;i++)
    {
        int a;
        cin>>a;
        if(a==0)
        {
            int a,b;
            cin>>a>>b;
            a++,b++;
            int k;
            cin>>k;
            arr[num[a]][b]=k;
        }
        else
        {
            int a,b;
            cin>>a>>b;
            a++,b++;
            int temp;
            temp=num[a];
            num[a]=num[b];
            num[b]=temp;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<arr[num[i]][j]<<" ";
        cout<<'\n';
    }
}