# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int ch[15][15];
int arr[100010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            int temp=(j+arr[i])/2;
            if(ch[j][temp])
            {
                q,push({ch[j][1],i});
            }
        }
        if(ch[arr[i]][1]==0) ch[arr[i]][1]=i;
        for(int j=1;j<=10;j++)
        {
            if(ch[j][0]==1 && ch[j][arr[i]]==0) ch[j][arr[i]]=i;
        }
    }
}