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
pair<ll,ll> arr[200010],brr[100010];
int ch[100010];
vector<ll> cycle[100010];
int num;
ll mn=1e9;
ll res;
int main()
{
    fastio;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first;
        arr[i].second=i;
        brr[i]=arr[i];
        mn=min(mn,arr[i].first);
    }
    sort(brr+1,brr+n+1);
    for(int i=1;i<=n;i++)
    {
        if(ch[i]) continue;
        int a=i;
        while(!ch[a])
        {
            ch[a]=1;
            cycle[num].push_back(arr[a].first);
            a=brr[a].second;
        }
        num++;
    }
    for(int i=0;i<num;i++)
    {
        ll sum=0;
        ll temp=1e16;
        for(int j=0;j<cycle[i].size();j++)
        {
            sum+=cycle[i][j];
            temp=min(temp,cycle[i][j]);
        }
        ll k=(sum-temp)+temp*((int)cycle[i].size()-1);
        res+=min(k,sum+mn*(int)cycle[i].size()+mn+temp);
    }
    cout<<res;
}