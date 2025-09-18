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
string s;
int main()
{
    fastio;
    cin>>n;
    cin>>s;
    int num=0,temp=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.' || s[i]=='|' || s[i]==':' || s[i]=='#')
        {
            num+=temp;
            temp=0;
        }
        else
        {
            temp*=10;
            temp+=s[i]-'0';
        }
    }
    num+=temp;
    cout<<num;
}
