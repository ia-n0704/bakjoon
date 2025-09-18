# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fastio;
    int a,b,c;
    cin>>a>>b>>c;
    if(a==11)
    {
        if(b<11 || (b==11 && c<11))
        {
            cout<<-1;
            return 0;
        }
    }
    int cnt=0;
    int x=11,y=11,z=11;
    while(1)
    {
        if(a==x && b==y && c==z) break;
        z++;
        if(z==60)
        {
            y++;
            z=0;
        }
        if(y==24)
        {
            x++;
            y=0;
        }
        cnt++;
    }
    cout<<cnt;
}