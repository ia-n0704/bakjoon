# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[300010],ch[300010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int st=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        ch[arr[i]]=i;
        if(arr[i]==-1)
            st=i;
    }
    int idx=st;
    for(int i=0;i<n;i++)
    {
        cout<<idx<<" ";
        idx=ch[idx];
    }
}