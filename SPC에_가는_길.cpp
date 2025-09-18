# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int ax,ay,bx,by,cx,cy;
int main()
{
    fastio;
    int res=1;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if(ax==bx && bx==cx && ((ay<cy && cy<by) || (by<cy && cy<ay)))
        res++;
    else if(ax==bx) res--;
    if(ay==by && by==cy && ((ax<cx && cx<bx) || (bx<cx && cx<ax)))
        res++;
    else if(ay==by) res--;
    cout<<res;
}