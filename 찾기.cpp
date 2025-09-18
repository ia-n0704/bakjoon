# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
string s,t;
int pi[1000010];
vector<int> v;
void piset()
{
    int j=0;
    for(int i=1;i<t.length();i++)
    {
        while(j>0 && t[i]!=t[j])
            j=pi[j-1];
        if(t[i]==t[j])
            pi[i]=++j;
    }
}
void kmp()
{
    int j=0;
    for(int i=0;i<s.length();i++)
    {
        while(j>0 && s[i]!=t[j])
            j=pi[j-1];
        if(s[i]==t[j])
        {
            if(j==t.length()-1)
            {
                v.push_back(i-t.length()+1);
                j=pi[j];
            }
            else j++;
        }
    }
}
int main()
{
    fastio;
    getline(cin,s);
    getline(cin,t);
    piset();
    kmp();
    cout<<v.size()<<'\n';
    for(auto i:v)
        cout<<i+1<<" ";
}