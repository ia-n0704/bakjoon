# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int n,arr[1000010],num[1000010],dp[1000010],cnt;
int main()
{
    fastio;
    int i,idx=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    num[cnt++]=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>num[cnt-1])
        {
            dp[i]=cnt;
            num[cnt]=arr[i];
            cnt++;
        }
        else
        {
            idx=lower_bound(num,num+cnt,arr[i])-num;
            num[idx]=arr[i];
            dp[i]=idx;
        }
    }
    cout<<cnt<<'\n';
    int temp=cnt;
    cnt--;
    for(i=n-1;i>=0;i--)
    {
        if(dp[i]==cnt)
        {
            num[cnt--]=i+1;
            if(cnt<0)
                break;
        }
    }
    for(i=0;i<temp;i++)
        cout<<num[i]<<" ";
}