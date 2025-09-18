#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int t;
vector<ll> v;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(ll i=1;i*i<10'000'000'000'000;i++)
        v.push_back(i*i);
    ll cnt=0;
    for(int i=0;i<v.size();i++)
    {
        n=v[i];
        ll temp=n,res=0;
        while(temp)
        {
            res=res*10+temp%10;
            temp/=10;
        }
        ll l=1,r=1e9;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(mid*mid>=n) r=mid-1;
            else l=mid+1;
        }
        if(l*l!=n)
        {
            //cout<<"NO\n";
            continue;
        }
        l=1,r=1e9;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(mid*mid>=res) r=mid-1;
            else l=mid+1;
        }
        if(l*l!=res)
        {
            //cout<<"NO\n";
            continue;
        }
        //cout<<n<<'\n';
        cnt++;
    }
    cout<<cnt;
}