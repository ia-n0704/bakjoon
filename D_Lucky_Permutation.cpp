# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[200010];
int ch[200010];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    fill(ch,ch+n+1,0);
    int flag=1;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int cur=i;
        vector<int> v;
        int cnt=0;
        while(ch[cur]==0)
        {
            ch[cur]=1;
            v.push_back(cur);
            cur=arr[cur];
            cnt++;
        }
        cnt--;
        res+=max(0,cnt);
        sort(v.begin(),v.end());
        for(int j=1;j<v.size();j++)
        {
            if(v[j]==v[j-1]+1) flag=0;
        }
    }
    if(flag==0) res--;
    else res++;
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