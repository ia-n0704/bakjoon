# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[200010],brr[200010];
int cnt[1000010];
int ch[1000010];
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=m;i++) 
    {
        cin>>brr[i];
        ch[brr[i]]++;
    }
    int l=1,r=k;
    int num=0;
    int res=0;
    for(int i=l;i<=r;i++)
    {
        if(ch[arr[i]]>cnt[arr[i]])
        {
            cnt[arr[i]]++;
            num++;
        }
        if(num>=k)
            res++;
    }
    for(l=l+1,r=r+1;r<=n;l++,r++)
    {
        if(num)
    }
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