# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol()
{
    string a,b;
    cin>>a>>b;
    int mx=0;
    for(int i=0;i<b.length();i++)
    {
        int idx=i;
        for(int j=0;j<a.length();j++)
        {
            if(idx<b.length() && a[j]==b[idx])
                idx++;
        }
        mx=max(mx,idx-i);
    }
    cout<<a.length()+b.length()-mx<<'\n';
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