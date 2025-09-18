# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[200010];
void sol()
{
    cin>>n;
    int odd=0;
    ll mx=0,mx2=0;
    vector<ll> v;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2)
        {
            odd++;
            mx=max(mx,arr[i]);
        }
        else
        {
            v.push_back(arr[i]);
        }
    }
    sort(v.begin(),v.end());
    int cnt=0;
    if(odd==0)
    {
        cout<<0<<'\n';
        return;
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]%2==0)
        {
            if(v[i]>mx)
            {
                mx=1e16;
                cnt+=2;
            }
            else
            {
                if(mx<1e16) mx+=v[i];
                cnt++;
            }            
        }
    }
    cout<<cnt<<'\n';
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