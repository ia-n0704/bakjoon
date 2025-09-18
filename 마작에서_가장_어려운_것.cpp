# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int a,b,c;
int main()
{
    fastio;
    cin>>a>>b>>c;
    int resa=a/3+(a%3?1:0);
    c-=a%3==0?0:3-a%3;
    int resb=b/4+(b%4?1:0);
    c-=b%4==0?0:4-b%4;
    if(c<0)
    {
        cout<<-1;
        return 0;
    }
    int mn=1000000,mn2;
    for(int i=c;i>=0;i-=4)
    {
        if(i%3==0)
            mn=i/3;
    }
    if(mn==1000000)
    {
        cout<<-1;
        return 0;
    }
    resa+=mn;
    c-=mn*3;
    resb+=c/4;
    cout<<resa<<" "<<resb;
}
