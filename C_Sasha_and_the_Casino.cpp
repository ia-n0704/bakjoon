# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    long long a,b,c;
    cin>>a>>b>>c;
    int num=c;
    for(int i=1;i<=b;i++)
    {
        int l=1,r=num;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(num+mid*(a-1)<=c)
                l=mid+1;
            else r=mid-1;
        }
        num-=l;
        if(num<=0)
        {
            cout<<"NO\n";
            return;
        }
    }
    if(num+num*(a-1)>c)
        cout<<"YES\n";
    else cout<<"NO\n";
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