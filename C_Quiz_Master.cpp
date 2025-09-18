# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[100010];
int ch[100010];
int v[100010];
void sol()
{
    int n,m;
    cin>>n>>m;
    int mn=m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        arr[a]=1;
    }
    for(int i=m;i>=1;i--)
    {
        if(ch[i]) continue;
        if(arr[i]==0)
        {
            cout<<-1<<'\n';
            return;
        }
        ch[i]=1;
        mn=min(mn,i);
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                ch[i/j]=1;
                ch[j]=1;
            }
        }
    }
    fill(arr,arr+)
    cout<<m-mn<<'\n';
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}