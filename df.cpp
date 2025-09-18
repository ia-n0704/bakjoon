#include <bits/stdc++.h>
using namespace std;
int arr[100010],brr[100010];
int n;
int check()
{
    for(int i=1;i<=n;i++)
    {
        int l=0,r=0;
        for(int j=1;j<=2*n;j++)
        {
            if(brr[j]==i)
            {
                if(l==0) l=j;
                else r=j;
            }
        }
        if(r-l-1!=i) return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)
        arr[i]=i;
    do
    {
        for(int i=1;i<=2*n;i++)
            brr[i]=(arr[i]-1)%n+1;
        if(check())
        {
            for(int i=1;i<=2*n;i++)
                cout<<brr[i]<<" ";
            cout<<'\n';
        }
    } while (next_permutation(arr+1,arr+2*n+1));
    
}