# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,d;
void sol()
{
    cin>>n>>d;
    cout<<1;
    if(n>=3 || d%3==0) cout<<" 3";
    if(d==5) cout<<" 5";
    if(d==7 || n>=3) cout<<" 7";
    if(d==9 || n>=6) cout<<" 9";
    else if(d==3 || d==6)
    {
        if(n>=3) cout<<" 9";
    }
    cout<<'\n';
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