# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[100010];
int res[100010];
void sol()
{
    vector<pair<int,int>> v1,v2;
    int n;
    int flag;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1) flag=(i+1)%2;
    }
    for(int i=1;i<=n;i++)
    {
        if((flag==1 && i==1) || (flag==0 && i==n)) continue;
        if((i+flag)%2) v1.push_back({arr[i],i});
        else v2.push_back({arr[i],i});
    }
    int cnt=n/2;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(auto i:v1)
        res[i.second]=cnt--;
    cnt=n;
    for(auto i:v2)
        res[i.second]=cnt--;
    if(flag==0)
        res[n]=n/2+1;
    else res[1]=n/2+1;
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
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