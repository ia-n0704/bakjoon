# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int arr[1010][1010];
int num[1010][1010];
int n,m;
int res;
int main()
{
    fastio;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>arr[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i-1][j]==arr[i][j]) num[i][j]=num[i-1][j];
            num[i][j]++;
        }
    }
    stack<pair<int,int>> st;
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j-1]!=arr[i][j])
            {
                while(!st.empty()) st.pop();
                sum1=0;
            }
            sum2=1;
            while(!st.empty() && st.top().first>=num[i][j])
            {
                sum2+=st.top().second;
                sum1-=(st.top().first*st.top().second);
                st.pop();
            }
            st.push({num[i][j],sum2});
            sum1+=(num[i][j]*sum2);
            res+=sum1;
        }
    }
    cout<<res;
}