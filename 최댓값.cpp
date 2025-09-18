#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const ll mx=1e16;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int res,resi,resj;
int main()
{
    fastio;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int a;
            cin>>a;
            if(res<=a)
            {
                res=a;
                resi=i;
                resj=j;
            }
        }
    }
    cout<<res<<'\n';
    cout<<resi<<" "<<resj;
}