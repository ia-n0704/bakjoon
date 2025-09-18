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
int arr[2000];
int x,y,z;
int main()
{
    fastio;
    for(int i=1;i<=4;i++) cin>>arr[i];
    cin>>x>>y>>z;
    int flag=0;
    int l=x-z,r=x+z;
    for(int i=1;i<=4;i++)
    {
        if(arr[i]==x)
        {
            cout<<i<<" ";
            flag=1;
        }
    }
    if(flag==0) cout<<0;
}
