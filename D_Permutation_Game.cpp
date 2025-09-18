# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200010],brr[200010];
ll resa,resb;
ll cha[200010],chb[200010];
void sol()
{
    ll n,k,sta,stb;
    cin>>n>>k>>sta>>stb;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
        cin>>brr[i];
    fill(cha,cha+n+1,0);
    fill(chb,chb+n+1,0);
    ll sum=0;
    ll idx=sta;
    int temp=1;
    while(k>=temp)
    {
        if(cha[idx]) break;
        sum+=brr[idx];
        ll num=sum+(k-temp)*brr[idx];
        resa=max(resa,num);
        cha[idx]=1;
        temp++;
        idx=arr[idx];
    }
    sum=0;
    idx=stb;
    temp=1;
    while(k>=temp)
    {
        if(chb[idx]) break;
        sum+=brr[idx];
        ll num=sum+(k-temp)*brr[idx];
        resb=max(resb,num);
        chb[idx]=1;
        temp++;
        idx=arr[idx];
    }
    if(resa>resb)
        cout<<"Bodya\n";
    else if(resa<resb)
        cout<<"Sasha\n";
    else cout<<"Draw\n";
    fill(cha,cha+n+1,0);
    fill(chb,chb+n+1,0);
    resa=0;
    resb=0;
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