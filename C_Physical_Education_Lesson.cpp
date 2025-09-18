# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n,m;
    cin>>n>>m;
    int res=0;
    int a=n-(m-2);
    set<int> s;
    for(int i=a;i>0;i/=2)
    {
        if(i%2==0)
        {
            s.insert(i);
            s.insert(i)
            res++;
        }
    }
    a=n-m;
    for(int i=a;i>0;i/=2)
    {
        if(i%2==0) 
        {
            if(!s.count(i))
                res++;
        }
    }
    cout<<res<<'\n';
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