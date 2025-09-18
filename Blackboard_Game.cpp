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
int n;
int cnt[200010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=3*n;i++)
    {
        int a;
        cin>>a;
        cnt[a+100000]++;
    }
    for(int i=0;i<=200000;i++)
    {
        if(cnt[i]%3!=0)
        {
            cout<<"Y";
            return 0;
        }
    }
    cout<<"N";
}
