#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;
map<ll,int> m;
vector<ll> ans[1010];
pair<ll,ll> ans2[1010];
int main()
{
    cin>>t;
    int idx=1;
    while(t--)
    {
        cin>>n;
        ll t=m[n];
        if(t!=0)
        {
            cout<<ans2[t].first<<" "<<ans2[t].second<<'\n';
            for(auto i:ans[t])
                cout<<i<<" ";
            cout<<'\n';
            continue;
        }
        vector<ll> res;
        ll mx=0;
        for(int i=2;i<=n;i++)
        {
            ll num=n;
            ll cnt=0,temp=0;
            while(num)
            {
                if(!(num%i)) cnt++;
                temp++;
                num/=i;
            }
            if(mx<cnt) res.clear();
            if(mx<=cnt) res.push_back(i);
            mx=max(mx,cnt);
            if(temp<=mx) break;
        }
        m[n]=idx;
        ans2[idx]={mx,res.size()};
        ans[idx++]=res;
        cout<<mx<<" "<<res.size()<<'\n';
        for(auto i:ans[idx-1]) cout<<i<<" ";
        cout<<'\n';
    }
}