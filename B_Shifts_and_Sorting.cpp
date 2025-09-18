# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sol()
{
    string s;
    cin>>s;
    ll cnt=0,res=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
            cnt++;
        else 
        {
            if(cnt!=0) res+=cnt+1;
        }
    }
    cout<<res<<'\n';
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