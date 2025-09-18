# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100010];
vector<int> v[100010];
void sol()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
        v[arr[i]].push_back(i);
    int l=0,r=n-1;
    for(int i=0;i<n;i++)
    {
        if(v[i].size()==0)
        {
            break;
        }
        l=max(l,v[i][0]);
        r=min(r,v[i][v[i].size()-1]-1);
    }
    if(l<=r)
    {
        cout<<2<<'\n';
        cout<<1<<" "<<l+1<<'\n';
        cout<<l+2<<" "<<n<<'\n';
    }
    else
    {
        cout<<-1<<'\n';
    }
    for(int i=0;i<n;i++) v[i].clear();
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