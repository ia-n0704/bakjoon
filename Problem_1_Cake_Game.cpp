#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll arr[500010];
ll sum[500010];
ll n;
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    ll mx=0;
    ll k;
    if(n%2) k=n/2;
    else k=n/2-1;
    for(int i=0;i<=k;i++){
        ll idx=n-k+i;
        mx=max(mx,sum[i]+sum[n]-sum[idx]);
    }
    cout<<sum[n]-mx<<" "<<mx<<'\n';
}
int main(){
    fastio;
    int t;
    cin>>t;
    while(t--) sol();
}