# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    int n;
    int arr[100][100];
    cin>>n;
    string s[100];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<n;j++)
            arr[i][j]=s[i][j]-'0';
    }
    int mni=100,mxi=-1,mnj=100,mxj=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j])
            {
                mni=min(mni,i);
                mxi=max(mxi,i);
                mnj=min(mnj,j);
                mxj=max(mxj,j);
            }
        }
    }
    if(mxi-mni==mxj-mnj)
        cout<<"SQUARE\n";
    else cout<<"TRIANGLE\n";
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