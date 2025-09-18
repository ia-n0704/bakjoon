# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
vector<ll> v1,v2,v3,v4,v5,v6;
ll n,m,q;
int main()
{
    fastio;
    cin>>n>>m>>q;
    for(ll i=1;i<=m;i++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b==d)
            v1.push_back(b);
        else if(a==c)
            v2.push_back(a);
        else
        {
            ll x=(c-a)/(d-b);
            //cout<<x<<'\n';
            if(x==1)
                v3.push_back(a-(b-1));
            else v4.push_back(a+(b-1));
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    sort(v4.begin(),v4.end());
    while(q--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>d)
        {
            swap(a,c);
            swap(b,d);
        }
        ll idx=lower_bound(v1.begin(),v1.end(),b)-v1.begin();
        if(idx!=v1.size() && b<=v1[idx] && d>=v1[idx])
        {
            cout<<0<<'\n';
            continue;
        }            

        if(a>c)
        {
            swap(a,c);
            swap(b,d);
        }
        idx=lower_bound(v2.begin(),v2.end(),a)-v2.begin();
        if(idx!=v2.size() && a<=v2[idx] && c>=v2[idx])
        {
            cout<<0<<'\n';
            continue;
        }            

        ll temp1=a-(b-1),temp2=c-(d-1);
        //cout<<temp1<<" "<<temp2<<'\n';
        if(temp1>temp2) swap(temp1,temp2);
        idx=lower_bound(v3.begin(),v3.end(),temp1)-v3.begin();
        if(idx!=v3.size() && temp1<=v3[idx] && temp2>=v3[idx])
        {
            cout<<0<<'\n';
            continue;
        }

        temp1=a+(b-1),temp2=c+(d-1);
        if(temp1>temp2) swap(temp1,temp2);
        idx=lower_bound(v4.begin(),v4.end(),temp1)-v4.begin();
        if(idx!=v4.size() && temp1<=v4[idx] && temp2>=v4[idx])
        {
            cout<<0<<'\n';
            continue;
        }

        cout<<1<<'\n';
    }
}