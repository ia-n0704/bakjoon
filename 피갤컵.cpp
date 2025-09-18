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
int a=2024,b=8;
int main()
{
    fastio;
    for(int i=1;i<=10000;i++)
    {
        cout<<"    if(n=="<<i<<") cout<<"<<a<<" "<<b<<";\n";
        b+=7;
        if(b>12)
        {
            b-=12;
            a+=1;
        }
    }
}
