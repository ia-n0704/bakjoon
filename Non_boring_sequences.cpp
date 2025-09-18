# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int n,arr[200010];
int fir[200010],sec[200010];
int dnc(int s,int e)
{
    if(s>e) return 1;
    //cout<<s<<" "<<e<<'\n';
    for(int i=s;i<=(s+e)/2;i++)
    {
        if(fir[i]<s && sec[i]>e) 
        {
            int a=dnc(s,i-1);
            int b=dnc(i+1,e);
            if (a && b) return 1;
            else
                return 0;
        }
        else if(fir[e-i+s]<s && sec[e-i+s]>e)
        {
            int a=dnc(s,e-i+s-1);
            int b=dnc(e-i+s+1,e);
            if (a && b) return 1;
            else
                return 0;
        }
    }
    return 0;
}
void sol()
{
    cin>>n;
    map<int,int> m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        fir[i]=m[arr[i]];
        sec[m[arr[i]]]=i;
        m[arr[i]]=i;
        sec[i]=n+1;
    }
    int flag=dnc(1,n);
    if(flag) cout<<"non-boring\n";
    else cout<<"boring\n";
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