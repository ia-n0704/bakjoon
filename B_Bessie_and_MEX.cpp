# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int mex[200010];
int arr[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int m=0;
    for(int i=0;i<n;i++)
    {
        int num=m-arr[i];
        //cout<<num<<'\n';
        if(arr[i]==1) num++;
        num=max(m,num);
        cout<<num<<" ";
        mex[num]=1;
        while(mex[m])
            m++;
    }
    cout<<'\n';
    fill(mex,mex+m+1,0);
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