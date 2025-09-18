# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[200010];
int ans[200010];
void sol()
{
    int n;
    int q;
    cin>>n;
    fill(ans,ans+n+1,-1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        int j;
        for(j=max(i+1,ans[i-1]);j<=n;j++)
        {
            if(arr[i]!=arr[j])
            {
                ans[i]=j;
                break;
            }
        }
        if(ans[i]==-1)
            ans[i]=n+1;
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(ans[a]<=b)
        {
            cout<<a<<" "<<ans[a]<<'\n';
        }
        else cout<<-1<<" "<<-1<<'\n';
    }
    cout<<'\n';
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