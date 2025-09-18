# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int a1,b1,c1,d1,e1,f1;
int a2,b2,c2,d2,e2,f2;
int main()
{
    fastio;
    cin>>a1>>b1>>c1>>d1>>e1>>f1;
    int num=a1*13+b1*7+c1*5+d1*3+e1*3+f1*2;
    cin>>a2>>b2>>c2>>d2>>e2>>f2;
    int num2=a2*13+b2*7+c2*5+d2*3+e2*3+f2*2;
    if(num<=num2+1.5) cout<<"ekwoo";
    else cout<<"cocjr0208";
}