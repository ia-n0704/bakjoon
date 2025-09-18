# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[505];
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) arr[i]=i;
    int res=0;
    int num=1;
    for(int i=1;i<=n;i++)
    {
        res+=i*num;
        num+=2;
    }
    cout<<res<<" "<<2*n<<'\n';
    for(int i=1;i<=n*2/4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(j==1)
            {
                cout<<1<<" "<<i<<" ";
                for(int r=1;r<=n;r++)
                    cout<<arr[r]<<" ";
                cout<<'\n';
            }
            else if(j==2)
            {
                cout<<2<<" "<<i<<" ";
                for(int r=n;r>=1;r--)
                    cout<<arr[r]<<" ";
                cout<<'\n';
            }
            else if(j==3)
            {
                cout<<1<<" "<<i<<" ";
                for(int r=n;r>=1;r--)
                    cout<<arr[r]<<" ";
                cout<<'\n';
            }
            else 
            {
                swap(arr[i],arr[i+1]);
                cout<<2<<" "<<i<<" ";
                for(int r=1;r<=n;r++)
                    cout<<arr[r]<<" ";
                cout<<'\n';
            }
        }
    }
    for(int i=1;i<=n*2-(n*2/4*4);i++)
    {
        if(i==1)
        {
            cout<<1<<" "<<n*2/4+1<<" ";
            for(int r=1;r<=n;r++)
                cout<<arr[r]<<" ";
            cout<<'\n';
        }
        else if(i==2)
        {
            cout<<2<<" "<<n*2/4+1<<" ";
            for(int r=n;r>=1;r--)
                cout<<arr[r]<<" ";
            cout<<'\n';
        }
        else if(i==3)
        {
            cout<<1<<" "<<n*2/4+1<<" ";
            for(int r=n;r>=1;r--)
                cout<<arr[r]<<" ";
            cout<<'\n';
        }
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