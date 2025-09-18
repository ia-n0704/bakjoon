# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
string str[1010];
string t[1010];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[1010];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>str[i];
        t[i].resize(10);
        for(int j=0;j<7;j++)
        {
            string temp;
            cin>>temp;
            if(j<3) t[i][j]=temp[0];
        }
    }
    for(int i=0;i<m;i++)
    {
        int num=-1;
        string comp;
        comp.resize(10);
        for(int j=0;j<3;j++)
        {
            string temp;
            cin>>temp;
            //cout<<temp[0]<<'\n';
            comp[j]=temp[0];
        }
        for(int j=0;j<n;j++)
        {
            //cout<<t[j]<<'\n';
            if(comp==t[j])
            {
                //cout<<comp<<'\n';
                //cout<<num<<" "<<j<<'\n';
                if(num==-1)
                    num=j;
                else num=-2;
            }
        }
        if(num==-2)
            cout<<'?'<<'\n';
        else if(num==-1)
            cout<<'!'<<'\n';
        else cout<<str[num]<<'\n';
    }
}