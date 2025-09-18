# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n,t,brr[100010],f[100010],FR[100010];
pii arr[100010];
int main()
{
    fastio;
    cin>>n>>t;
	for(int i=1;i<=n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=1;i<=n;i++)
        brr[i]=arr[i].second;
	sort(arr+1,arr+n+1); 
    sort(brr+1,brr+n+1);
	for(int i=1;i<=n;i++) 
    {
        f[i]=brr[i];
        FR[i]=arr[i].first;
    }
	for(int i=n;i>0;i--) 
    {
        int temp=n;
        for(int j=n;j>0;j--)
        {
            if(brr[j]<arr[i].second) break;
		    f[j]-=t;
            while(temp>i)
            {
                if(f[j]>=arr[temp].first)
                    break;
                else 
                {
                    f[j]=min(f[j],FR[temp]);
                    temp--;
                }
            }
            if(f[j]<arr[i].first)
            {
                cout<<"no";
                return 0;
            }
            else
                FR[i]=min(FR[i],f[j]-t);
        }
	}
	cout<<"yes";
}