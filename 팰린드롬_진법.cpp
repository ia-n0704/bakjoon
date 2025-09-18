#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> res;
int main()
{
    ll n;
    cin>>n;
    if(n==2) return 0;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0 && n/i-1>i) res.push_back(n/i-1);
        if(i==1) continue;
        vector<ll> v;
        ll num=1;
        while(num<=n) num*=i;
        num/=i;
        ll temp=n;
        while(num)
        {
            v.push_back(temp/num);
            temp%=num;
            num/=i;
        }
        int flag=0;
        for(int j=0;j<v.size()/2;j++)
        {
            if(v[j]!=v[v.size()-j-1]) flag=1;
        }
        if(flag==0) res.push_back(i);
    }
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    for(auto i:res) cout<<i<<'\n';
}