# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
pair<int,int> arr[1010];
int ch[1010];
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first>>arr[i].second;
    int cnt=0;
    int res=0;
    int cur=0;
    while(1)
    {
        int flag=0;
        int mx=-1,mxidx=-1;
        for(int i=1;i<=n;i++)
        {
            if(ch[i]<2)
            {
                if(arr[i].second<=cur)
                {
                    cnt++;
                    res++;
                    cur+=2-ch[i];
                    ch[i]=2;
                    flag=1;
                    break;
                }
            }
            if(ch[i]<1)
            {
                if(cur>=arr[i].first)
                {
                    if(mx<arr[i].second)
                    {
                        mx=arr[i].second;
                        mxidx=i;
                        flag=2;
                    }
                }
            }
        }
        if(flag==0) break;
        if(flag==2)
        {
            ch[mxidx]=1;
            res++;
            cur++;
        }
    }
    if(cnt!=n) cout<<"Too Bad";
    else cout<<res;
}