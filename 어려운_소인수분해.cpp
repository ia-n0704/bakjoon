# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<int> p;
int ch[5000010];
int main()
{
    fastio;
    for(int i=2;i<=5000000;i++)
    {
        if(!ch[i]) 
        {
            ch[i]=i;
            p.push_back(i);
        }
        for(auto j:p)
        {
            if(i*j>5000000) break;
            ch[i*j]=j;
            if(i%j==0) break;
        }
    }
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        while(a>1)
        {
            cout<<ch[a]<<" ";
            a/=ch[a];
        }
        cout<<'\n';
    }
}