# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s,str[10010];
int pi[501][10001];
int dp[100010];
int idx[10010];
int n;
void piset(int k)
{
    int j=0;
    for(int i=1;i<str[k].length();i++)
    {
        while(j>0 && str[k][i]!=str[k][j])
            j=pi[k][j-1];
        if(str[k][i]==str[k][j])
            pi[k][i]=++j;
    }
}
void kmp()
{
    for(int i=0;i<s.length();i++)
    {
        if(i>0) dp[i]=dp[i-1];
        for(int j=1;j<=n;j++)
        {
            while(idx[j]>0 && s[i]!=str[j][idx[j]])
                idx[j]=pi[j][idx[j]-1];
            if(s[i]==str[j][idx[j]])
            {
                if(idx[j]==str[j].length()-1)
                {
                    if(i-(int)str[j].length()<0)
                        dp[i]=(int)str[j].length();
                    else dp[i]=max(dp[i],dp[max(0,i-(int)str[j].length())]+(int)str[j].length());
                    idx[j]=pi[j][idx[j]];
                }
                else idx[j]++;
            }
        }
    }
}
int main()
{
    fastio;
    cin>>s;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>str[i];
    for(int i=1;i<=n;i++)
        piset(i);
    kmp();
    cout<<dp[s.length()-1];
}  