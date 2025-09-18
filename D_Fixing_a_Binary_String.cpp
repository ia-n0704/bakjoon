# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string s;
void sol()
{
    cin>>n>>k;
    cin>>s;
    int num=0;
    for(int i=0;i<n-k;i++)
    {
        if(s[i]==s[i+k]) num=i=1;
        else if(i<k && i>0 && s[i]!=s[i-1]) num=i-1;
    }
        
    int flag=0;
    for(int i=num+1;i<n+num-k+1;i++)
    {
        int l=i,r=i+k;
        //cout<<num<<" | "<<l<<" "<<r<<'\n';
        l%=n,r%=n;
        if(s[l]==s[r]) flag=1;
    }
    if(flag) cout<<-1<<'\n';
    else cout<<num+1<<'\n';
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