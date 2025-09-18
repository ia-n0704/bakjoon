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
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll res1=a*b;
        string res2;
        string x=to_string(a),y=to_string(b);
        if(x.length()>y.length())
            swap(x,y);
        for(int i=0;i<y.length()-x.length();i++)
            res2+=y[i];
        for(int i=y.length()-x.length();i<y.length();i++)
        {
            int idx=i-y.length()+x.length();
            ll temp=(x[idx]-'0')*(y[i]-'0');
            res2+=to_string(temp);
        }
        if(to_string(res1)==res2) cout<<1<<'\n';
        else cout<<"0\n";
    }
}
