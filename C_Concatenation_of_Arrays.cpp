# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<int,int> arr[100010];
int ch[100010];
void sol()
{
    cin>>n;
    fill(ch,ch+n+1,0);
    vector<pair<int,int>> v2;
    vector<int> v;
    map<int,int> m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        v.push_back(arr[i].first);
        v.push_back(arr[i].second);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<v.size();i++) m[v[i]]=i+1;
    for(int i=1;i<=n;i++)
    {
        v2.push_back({m[arr[i].first]+m[arr[i].second],i});
    }
    sort(v2.begin(),v2.end());
    for(auto i:v2)
    {
        if(ch[i.second]==0)
        {
            ch[i.second]=1;
            cout<<arr[i.second].first<<" "<<arr[i.second].second<<" ";
        }
    }
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