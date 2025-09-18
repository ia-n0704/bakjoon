# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[510];
string t[510];
int arr[510][510];
int brr[510][510];
void sol()
{
    int n,m;
    int flag=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) arr[i][j]=s[i][j]-'0';
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) brr[i][j]=t[i][j]-'0';
    for(int i=0;i<m;i++)
    {
        int temp=0;
        for(int j=0;j<n;j++)
        {
            //cout<<arr[i][j]<<" "<<brr[i][j]<<'\n';
            temp+=(brr[j][i]+3-arr[j][i])%3;
        }
        //cout<<'\n';
        if(temp%3) flag=1;
    }
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=0;j<m;j++)
        {
            temp+=(brr[i][j]+3-arr[i][j])%3;
        }
        if(temp%3) flag=1;
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
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