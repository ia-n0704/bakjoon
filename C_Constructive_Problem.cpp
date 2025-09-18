# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[200010];
void sol()
{
    int n;
    int flag=0;
    cin>>n;
    int num=0;
    vector<pair<int,int>> v;
    vector<int> first,second;
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(n==1)
    {
        if(arr[1]!=0)
            cout<<"Yes\n";
        else cout<<"No\n";
        return;
    }
    for(int i=1;i<=n;i++)
        v.push_back({arr[i],i});
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(v[i].first>num) 
            break;
        else num=v[i].first+1;
    }
    for(int i=0;i<n;i++)
    {
        if(v[i].first==num+1)
            first.push_back(v[i].second);
        else if(v[i].first==num-1)
            second.push_back(v[i].second);
    }
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    if(num==n)
    {
        cout<<"No\n";
        return;
    }
    //cout<<first.size()<<" "<<second.size()<<'\n';
    if(num==0 || first.size()==0)
    {
        cout<<"Yes\n";
        return;
    }
    int l=first[0],r=first[first.size()-1];
    if(second[0]<l || second[second.size()-1]>r) flag=1;
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
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