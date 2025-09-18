# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll arr[201][201];
void sol()
{
    cin>>n>>m;
    cout<<n*m<<'\n';
    ll num=1024;
    ll temp=1024;
    ll num2=(1ll<<40);
    int flag=1;
    for(int i=1;i<=m;i+=2)
    {
        /*if(temp-n*2<=0)
        {
            temp*=2;
            num=temp;            
        }
        temp-=n*2;*/
        temp+=1024;
        num=temp;
        for(int j=1;j<=n;j+=2)
        {
            if(j==n)
            {
                if(i!=1)
                num2^=arr[1][i]^arr[1][i-1];
                arr[j][i]=num2;
                if(i!=m)
                {
                    arr[j][i+1]=arr[j][i]+2;
                    num2=arr[j][i+1];
                }
                continue;
            }
            arr[j][i]=num;
            if(i!=m) arr[j][i+1]=num+2;
            num++;
            arr[j+1][i]=num;
            if(i!=m) arr[j+1][i+1]=num+2;
            num+=3;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<arr[i][j]<<" ";         
        }

        cout<<'\n';
    }
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