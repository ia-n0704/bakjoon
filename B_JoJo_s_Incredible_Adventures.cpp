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
    ll cnt=0,mx=0;
    if(s.length()==1)
    {
        if(s[0]=='0')
            cout<<0<<'\n';
        else cout<<"1\n";
        return;
    }
    ll flag=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0') flag=1;
        else cnt++;
    }
    if(flag==0)
    {
        cout<<cnt*cnt<<'\n';
        return;
    }
    cnt=0;
    s=s+s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1') 
            cnt++;
        else
            cnt=0;
        if(cnt>=1 && cnt<=s.length()/2)
            mx=max(mx,(cnt/2+cnt%2)*(cnt/2+1));        
    }
    if(cnt>=1 && cnt<=s.length()/2)
        mx=max(mx,(cnt/2+cnt%2)*(cnt/2+1)); 
    cout<<mx<<'\n';
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