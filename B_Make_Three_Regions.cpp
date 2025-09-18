# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[3];
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<=1;i++)
        cin>>s[i];
    int cnt=0;
    for(int i=1;i<n-1;i++)
    {
        if(s[0][i]=='.')
        {
            if(s[0][i-1]=='x' && s[0][i+1]=='x' && s[1][i]=='.' && s[1][i-1]=='.' && s[1][i+1]=='.')
                cnt++;
        }
        if(s[1][i]=='.')
        {
            if(s[1][i-1]=='x' && s[1][i+1]=='x' && s[0][i]=='.' && s[0][i-1]=='.' && s[0][i+1]=='.')
                cnt++;
        }
    }
    cout<<cnt<<'\n';
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