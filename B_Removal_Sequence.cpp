# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n,m;
    cin>>n>>m;
    int arr[200];
    int ch[200];
    fill(ch,ch+n+1,0);
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
        ch[arr[i]]=1;
    }
    for(int i=n;i>0;i--)
    {
        if(ch[i]==0)
        {
            cout<<i<<" ";
        }
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