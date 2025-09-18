# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[1010][1010];
int res[1010];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>arr[i][j];
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        int num=(1<<31)-1;
        int temp=0;
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            if(i>j)
                temp|=(arr[i][j]^res[j]);
            num&=arr[i][j];   
        }
        if(num==(1<<31)-1) num=0;
        res[i]=(num|temp);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            //cout<<(res[i]|res[j])<<" "<<arr[i][j];
            if((res[i]|res[j])!=arr[i][j]) flag=1;
        }
    }
    if(flag)
    {
        fill(res+1,res+n+1,0);
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<'\n';
    fill(res+1,res+n+1,0);
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