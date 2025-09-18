# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s="wbwbwwbwbwbw";
int main()
{
    fastio;
    int w,b;
    cin>>w>>b;
    int i;
    for(i=0;i<s.length();i++)
    {
        int idx=i;
        int cw=0,cb=0;
        while(1)
        {
            if(cw==w)
                break;
            if(s[idx++]=='w')
                cw++;
            else cb++;
            if(idx>=s.length())
                idx=0;
        }
        if(cb==b)
            break;
    }
    if(i!=s.length())
    {
        cout<<"Yes";
        return 0;
    }
    for(i=0;i<s.length();i++)
    {
        int idx=i;
        int cw=0,cb=0;
        while(1)
        {
            if(cb==b)
                break;
            if(s[idx++]=='w')
                cw++;
            else cb++;
            if(idx>=s.length())
                idx=0;
        }
        if(cw==w)
            break;
    }
    if(i!=s.length())
    {
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
}