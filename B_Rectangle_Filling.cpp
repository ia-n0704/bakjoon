# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
string s[510];
void sol()
{
    int n,m;
    cin>>n>>m;
    n--,m--;
    for(int i=0;i<n+1;i++) cin>>s[i];
    int flag=0;
    int idx=0;
    for(int i=0;i<n+1;i++)
    {
        if(s[i][m]==s[0][0])
            idx=1;
    }
    if(idx && (s[n][0]==s[0][0] || s[n][m]==s[0][0]))
    {
        cout<<"YES\n";
        return;
    }
    idx=0;
    for(int i=0;i<n+1;i++)
    {
        if(s[i][0]==s[0][m])
            idx=1;
    }
    if(idx && (s[n][0]==s[0][m] || s[n][m]==s[0][m]))
    {
        cout<<"YES\n";
        return;
    }
    idx=0;
    for(int i=0;i<m+1;i++)
    {
        if(s[n][i]==s[0][0])
            idx=1;
    }
    if(idx && (s[0][m]==s[0][0] || s[n][m]==s[0][0]))
    {
        cout<<"YES\n";
        return;
    }
    idx=0;
    for(int i=0;i<m+1;i++)
    {
        if(s[0][i]==s[n][0])
            idx=1;
    }
    if(idx && (s[0][m]==s[0][0] || s[n][m]==s[0][0]))
    {
        cout<<"YES\n";
        return;
    }
    idx=0;
    cout<<"NO\n";
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