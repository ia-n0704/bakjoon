# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int arr[200010],brr[200010];
int cha[1000010],chb[1000010];
void sol()
{
    int n,m,k;
    int mna=0,mnb=0;
    int mxa=0,mxb=0;
    cin>>n>>m>>k;
    fill(cha,cha+k+1,0);
    fill(chb,chb+k+1,0);
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        cha[arr[i]]=1;
    }
    for(int i=0;i<m;i++)
    {
        cin>>brr[i];
        chb[brr[i]]=1;
    }
    for(int i=1;i<=k;i++)
    {
        if(cha[i]==1 && chb[i]==0)
            mna++;
        else if(cha[i]==0 && chb[i]==1)
            mnb++;
        if(cha[i]==1)
            mxa++;
        if(chb[i]==1)
            mxb++;
        if(cha[i]==0 && chb[i]==0)
        {
            cout<<"NO\n";
            return;
        }
    }
    //cout<<mxa<<" "<<mxb;
    if(max(mna,mnb)>k/2 || min(mxa,mxb)<k/2) cout<<"NO\n";
    else cout<<"YES\n";
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