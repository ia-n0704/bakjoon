# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int ch[10010];
void sol()
{
    int n;
    string s;
    cin>>n>>s;
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U') num++;
    }
    if(num%2)
        cout<<"YES\n";
    else cout<<"NO\n";
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