# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int L,k,c;
int arr[10010];
int main()
{
    fastio;
    cin>>L>>k>>c;
    for(int i=1;i<=k;i++)
        cin>>arr[i];
    sort(arr+1,arr+k+1);
    int l=0,r=L;
    while(l<=r)
    {
        //cout<<l<<" "<<r<<'\n';
        int mid=(l+r)/2;
        int flag=0;
        int sum=0;
        int num=0;
        int le=0;
        for(int i=1;i<=k;i++)
        {
            if(arr[i]-arr[i-1]>mid)
            {
                flag=1;
                break;
            }
            int temp=arr[i]-le;
            if(temp>mid)
            {
                le=arr[i-1];
                num++;
            }
        }
        if(L-le>mid)
        {
            le=arr[k];
            num++;
        }
        if(L-le>mid) flag=1;
        if(flag || num>c) l=mid+1;
        else r=mid-1;
    }
    cout<<l<<" ";
    int le=L;
    int ans=arr[1];
    int num=0;
    for(int i=k;i>=1;i--)
    {
        int temp=le-arr[i];
        if(temp>l)
        {
            ans=arr[i+1];
            le=arr[i+1];
            num++;
        }
    }
    if(num<c) ans=arr[1];
    cout<<ans;
}
