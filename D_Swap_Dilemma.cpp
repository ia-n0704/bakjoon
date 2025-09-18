# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[200010],brr[200010],ch1[200010],ch2[200010],check[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        ch1[arr[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>brr[i];
        ch2[brr[i]]=i;
    }
    int cnt=0;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(ch2[arr[i]]==0)
            flag=1;
        if(ch1[arr[i]]==ch2[arr[i]] || check[i])
        {
            check[i]=1;
            continue;
        }
        int temp=i;
        while(1)
        {
            if(check[temp]) break;
            check[temp]=1;
            temp=ch2[arr[temp]];
        }
        cnt++;
    }
    if(flag || cnt%2) cout<<"NO\n";
    else cout<<"YES\n";
    for(int i=1;i<=n;i++)
    {
        ch1[arr[i]]=0;
        ch2[brr[i]]=0;
        check[i]=0;
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