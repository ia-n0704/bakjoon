# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200010],n;
ll num[200010];
ll ch[200010];
void sol()
{
    cin>>n;
    fill(num,num+n+1,0);
    fill(ch,ch+n+1,0);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        res+=arr[i];
    }
    ll temp=0;
    for(int i=1;i<=n;i++)
    {
        ch[arr[i]]++;
        if(ch[arr[i]]>=2)
            temp=max(temp,arr[i]);
        num[i]=temp;
    }
    ll cnt=0;
    temp=0;
    for(int i=1;i<=n;i++)
    {
        if(temp!=num[i])
        {
            res+=temp*cnt*(cnt+1)/2;
            temp=num[i];
            cnt=0;
        }
        cnt++;
    }
    //cout<<temp<<" "<<cnt<<'\n';
    res+=temp*cnt*(cnt+1)/2;
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