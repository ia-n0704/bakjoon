# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
int h,w,k;
string s[200010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>h>>w>>k;
    for(int i=0;i<h;i++)
        cin>>s[i];
    int res=200010;
    for(int i=0;i<h;i++)
    {
        int a=0,b=0;
        for(int j=0;j<w;j++)
        {
            if(s[i][j]=='x')
                a=b=0;
            else a++;
            if(s[i][j]=='o')
                b++;
            if(a>=k+1 && s[i][j-k]=='o')
                b--;
            if(a>=k)
                res=min(res,k-b);
        }
    }
    for(int i=0;i<w;i++)
    {
        int a=0,b=0;
        for(int j=0;j<h;j++)
        {
            if(s[j][i]=='x')
                a=b=0;
            else a++;
            if(s[j][i]=='o')
                b++;
            if(a>=k+1 && s[j-k][i]=='o')
                b--;
            if(a>=k)
                res=min(res,k-b);
        }
    }
    if(res==200010) cout<<-1;
    else
        cout<<res;
}