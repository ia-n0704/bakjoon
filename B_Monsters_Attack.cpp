# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct M
{
    ll a,x;
}arr[300010];
bool compare(M p,M q)
{
    if(p.x==q.x)
        return p.a<q.a;
    else return p.x<q.x;
}
void sol()
{
    ll n,k;
    ll mx=0;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i].a;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].x;
        arr[i].x=abs(arr[i].x);
    }
    sort(arr,arr+n,compare);
    ll temp=1;
    ll c=k;
    for(int i=0;i<n;i++)
    {
        if(arr[i].a<=c)
        {
            c-=arr[i].a;
        }
        else
        {
            arr[i].a-=c;
            ll num=arr[i].a/k+1;
            //if(arr[i].a%k) num++; 
            temp+=num;    
            c=k-arr[i].a%k;  
            //cout<<i<<" "<<temp<<'\n';
        }
        if(temp>arr[i].x && !(temp==arr[i].x+1 && c==k))
        {
            cout<<"NO\n";
            return;
        }
    }
    //cout<<temp<<" ";
    cout<<"YES\n";
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