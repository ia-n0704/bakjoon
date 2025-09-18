# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int m;
int main()
{
    fastio;
    cin>>m;
    if(m==1)
    {
        cout<<"1 1";
        return 0;
    }
    cout<<m/3+(bool)(m%3)<<" ";
    int cnt=0;
    int temp;
    while(m%4==0)
    {
        m/=4;
        cnt++;
    }
    temp=m;
    for(int i=2;i<=temp;i++)
    {
        while(m>1 && m%i==0)
        {
            m/=i;
            cnt++;
        }
    }
    cout<<cnt;
}