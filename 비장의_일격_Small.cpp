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
int n,k;
string s;
int main()
{
    fastio;
    cin>>n>>k;
    cin>>s;
    int res=n;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='X') continue;
        for(int j=i+1;j<n;j++)
        {
            if(s[j]==s[i])
            {
                int num=n-(j-i+1);
                res=min(res,num);
                for(int r=j+1;r<n;r++)
                {
                    if(s[r]=='X') continue;
                    for(int k=r+1;k<n;k++)
                    {
                        if(s[k]==s[r])
                            res=min(res,num-(k-r+1));
                    }
                }
            }
        }
    }
    cout<<res;
}
