# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int ch[200010];
int ans[200010];
int arr[200010];
void sol()
{
    string s;
    cin>>s;
    int n=(int)s.length();
    for(int i=0;i<n;i++)
        arr[i]=s[i]-'0';
    for(int i=0;i<n;i++)
    {
        int mx=arr[i];
        int mxidx=i;
        for(int j=i+1;j<=min(n-1,i+9);j++)
        {
            int num=arr[j]-j+i;
            if(num>mx)
            {
                mx=num;
                mxidx=j;
            }
        }
        for(int j=mxidx;j>i;j--)
        {
            arr[j]--;
            swap(arr[j],arr[j-1]);
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i];
    cout<<'\n';
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