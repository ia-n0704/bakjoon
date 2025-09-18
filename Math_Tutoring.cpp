#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int idx=0;
    while(t--)
    {
        idx++;
        cout<<"Case "<<idx<<": ";
        int n;
        cin>>n;
        cout<<n-1<<" ";
        for(int i=n;i>=0;i--)
        {
            int a;
            cin>>a;
            if(i>0)
                cout<<i*a<<" ";
        }
        cout<<'\n';
    }
}