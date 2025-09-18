# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int a,b,c;
int main()
{
    fastio;
    cin>>a>>b>>c;
    vector<int> v;
    for(int i=0;i<4;i++)
    {
        v.push_back(c%2);
        c/=2;
    }
    for(int i=0;i<4;i++)
    {
        v.push_back(b%2);
        b/=2;
    }
    for(int i=0;i<4;i++)
    {
        v.push_back(a%2);
        a/=2;
    }
    int num=0;
    for(int i=0;i<12;i++)
        num+=(1<<i)*v[i];
    if(num==0)
    {
        cout<<"0000";
        return 0;
    }
    int i;
    for(i=1;i<=1000;i*=10)
        if(num/i==0) break;
    while(i!=10000)
    {
        i*=10;
        cout<<0;
    }
    cout<<num;
}