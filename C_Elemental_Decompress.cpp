# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[200010],brr[200010],crr[200010];
int ch[200010];
vector<int> v[200010];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        ch[arr[i]]++;
        if(ch[arr[i]]>2) flag=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(ch[arr[i]]==1)
        {
            brr[i]=arr[i];
            crr[i]=arr[i];
        }
        else
            v[arr[i]].push_back(i);
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(ch[i]==0) q.push(i);
    for(int i=1;i<=n;i++)
    {
        if(v[i].empty()) continue;
        if(q.front()>i) flag=1;
        brr[v[i][0]]=i;
        crr[v[i][0]]=q.front();
        brr[v[i][1]]=q.front();
        crr[v[i][1]]=i;
        q.pop();
    }
    if(flag) cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++) cout<<brr[i]<<" ";
        cout<<'\n';
        for(int i=1;i<=n;i++) cout<<crr[i]<<" ";
        cout<<'\n';
    }
    for(int i=1;i<=n;i++)
    {
        ch[i]=0;
        v[i].clear();
    }
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