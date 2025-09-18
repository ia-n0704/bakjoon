# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fastio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int arr[2000010];
int n;
int main()
{
    fastio;
    cin>>n;
    int idx=1;
    if(n==1)
        cout<<"Yes\n0 0";
    else if(n==4)
        cout<<"Yes\n1 2 1 3 2 0 0 3";
    else if(n==5)
        cout<<"Yes\n4 1 3 1 2 4 3 2 0 0";
    else if(n%4==0)
    {
        for(int i=1;i<=n+1;i++)
        {
            if(i==n/2+1)
                arr[i]=n-2;
            else
            {
                if(i<n/2+1)
                    arr[i]=n-2*i+1;
                else arr[i]=(i-n/2-1)*2-1;
            }
                
        }
        idx=n+2;
        arr[idx++]=n/2-2;
        int num=n-4;
        while(num>=n/2)
        {
            arr[idx++]=num;
            num-=2;
        }
        num=n/2-4;
        while(num>=2)
        {
            arr[idx++]=num;
            num-=2;
        }
        num=2;
        arr[idx++]=n-2;
        arr[idx++]=n/2-2;
        while(num<=n/2-4)
        {
            arr[idx++]=num;
            num+=2;
        }
        arr[idx++]=0;
        arr[idx++]=0;
        num=n/2;
        while(num<=n-4)
        {
            arr[idx++]=num;
            num+=2;
        }
        cout<<"Yes\n";
        for(int i=1;i<=n*2;i++)
            cout<<arr[i]<<" ";
    }
    else if(n%4==1)
    {
        idx=1;
        n--;
        int num=n;
        while(num>=2)
        {
            arr[idx++]=num;
            num-=2;
        }
        arr[idx++]=n/2+1;
        arr[idx++]=n-1;
        num=2;
        while(num<=n-2)
        {
            arr[idx++]=num;
            num+=2;
        }
        arr[idx++]=n;
        arr[idx++]=n/2+1;
        num=n-3;
        while(num>=n/2+3)
        {
            arr[idx++]=num;
            num-=2;
        }
        num=n/2-1;
        while(num>=1)
        {
            arr[idx++]=num;
            num-=2;
        }
        arr[idx++]=n-1;
        num=1;
        while(num<=n/2-3)
        {
            arr[idx++]=num;
            num+=2;
        }
        arr[idx++]=n/2-1;
        arr[idx++]=0;
        arr[idx++]=0;
        num=n/2+3;

        while(num<=n-3)
        {
            arr[idx++]=num;
            num+=2;
        }
        cout<<"Yes\n";
        for(int i=1;i<=(n+1)*2;i++)
            cout<<arr[i]<<" ";
    }
    else cout<<"No";
}