# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010];
int b[200010];
int ch[200010];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int anum=0,bnum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<b[i])
        {
            bnum+=b[i];
            ch[i]=1;
        }
        else if(a[i]>b[i])
        {
            anum+=a[i];
            ch[i]=1;
        }
        else if(a[i]==0 && b[i]==0)
            ch[i]=1;
    }
    int minus=0,plus=0;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0)
        {
            if(a[i]==1) plus++;
            else minus++;
        }
    }
    int num=plus;
    //cout<<anum<<" "<<bnum<<" "<<num<<'\n';
    for(int i=num;i>0;i--)
    {
        if(anum>bnum)
            bnum++;
        else anum++;
    }
    num=-minus;
    for(int i=num;i<0;i++)
    {
        if(anum<bnum)
            bnum--;
        else
            anum--;
    }
    cout<<min(anum,bnum)<<'\n';
    fill(ch,ch+n+1,0);
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