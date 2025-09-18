# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol()
{
    int n;
    cin>>n;
    string s,t;
    int f1,f2;
    cin>>s>>t;
    int cnt1=0,cnt2=0;
    for(int i=0;i<s.length();i++)
        if(s[i]!=t[i]) cnt1++;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
        if(s[i]!=t[i]) cnt2++;
    if(cnt2%2) f2=0;
    else f2=-1;
    if(cnt1%2) f1=-1;
    else f1=0;        
    cnt1*=2;
    cnt2*=2;
    if(cnt1==0)
    {
        cout<<0<<'\n';
        return;
    }
    if(cnt2==0)
        cnt2=3;
    cout<<min(cnt1+f1,cnt2+f2)<<'\n';
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