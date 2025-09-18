#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll res;
ll arr[200020];
ll s_arr[200020];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        s_arr[i]=arr[i];
    }
    sort(s_arr,s_arr+n);
    for(int i=0;i<n;i++)
    {
        res+=i*(s_arr[i]-arr[i]);
        res%=mod;
    }
    printf("%lld",res);
}