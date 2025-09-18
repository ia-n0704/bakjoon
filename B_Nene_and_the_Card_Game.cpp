# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int ch[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ch[a]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==2) cnt++;
    }
    cout<<cnt<<'\n';
    fill(ch,ch+n+1,0);
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