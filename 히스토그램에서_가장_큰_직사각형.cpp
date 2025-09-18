#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100010];
ll res;
int main()
{
    while(1)
    {
        stack<ll> s;
        res=0;
        ll n,i;
        scanf("%lld",&n);
        if(n==0) break;
        for(i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        arr[n+1]=0;
        s.push(0);
        for(i=1;i<=n+1;i++)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            {
                ll check=s.top();
                s.pop();
                res=max(res,arr[check]*(i-s.top()-1));
            }
            s.push(i);
        }
        printf("%lld\n",res);
    }
}
