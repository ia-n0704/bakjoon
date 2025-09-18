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
pair<int,int> arr[1000];
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=0;i<n;i++)
    {
        int mx=-1;
        int mxidx=i;
        for(int j=0;j<n;j++)
        {
            if(mx<(arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second))
            {
                mx=(arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
                mxidx=j;
            }
        }
        cout<<mxidx+1<<'\n';
    }
}