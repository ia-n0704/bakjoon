# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s;
int cnt[1000];
int num[1000];
int main()
{
    fastio;
    cin>>s;
    int flag=0;
    for(int i=0;i<s.length();i++)
        cnt[s[i]-'a']++;
    for(int i=0;i<='z'-'a';i++)
        num[cnt[i]]++;
    for(int i=1;i<=s.length();i++)
        if(num[i]!=0 && num[i]!=2) flag=1;
    if(flag) cout<<"No";
    else cout<<"Yes";
}