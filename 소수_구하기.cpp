#include <bits/stdc++.h>
using namespace std;
int prime[10000010];
int sum[10000010];
int main()
{
    int q;
    prime[1]=1;
    for(int i=2;i<=10000000;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*2;j<=10000000;j+=i)
                prime[j]=1;
        }
    }
    for(int i=1;i<=10000000;i++)
        sum[i]=sum[i-1]+(prime[i]^1);
    cin>>q;
    while(q--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        cout<<sum[r]-sum[l-1]<<'\n';
    }
}