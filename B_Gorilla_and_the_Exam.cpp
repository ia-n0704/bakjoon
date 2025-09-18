# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n,k;
int arr[100010];
void sol()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    int cnt=1;
    vector<int> v;
    for(int i=2;i<=n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            v.push_back(cnt);
            cnt=1;
        }
        else cnt++;
    }
    v.push_back(cnt);
    sort(all(v));
    int res=v.size();
    for(auto i:v)
    {
        if(k<i) break;
        else
        {
            k-=i;
            res--;
        }
    }
    if(res<=0)
    {
        cout<<1<<'\n';
        return;
    }
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