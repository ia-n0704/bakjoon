#include <bits/stdc++.h>
using namespace std;
void go(int n,int l,int r)
{
    if(n==3)
    {
        cout<<2<<" to "<<-1<<endl;
        cout<<5<<" to "<<2<<endl;
        cout<<3<<" to "<<-3<<endl;
        return;
    }
    if(n<=7)
    {
        if(n==4)
        {
            cout<<r-2<<" to "<<l-2<<'\n';
            cout<<l+2<<" to "<<r-2<<'\n';
            cout<<l-1<<" to "<<l+2<<'\n';
            cout<<r-1<<" to "<<l-1<<'\n';
        }
        else if(n==5)
        {
            cout<<r-2<<" to "<<l-2<<'\n';
            cout<<l+2<<" to "<<r-2<<'\n';
            cout<<r-4<<" to "<<l+2<<'\n';
            cout<<l-1<<" to "<<r-4<<'\n';
            cout<<r-1<<" to "<<l-1<<'\n';
        }
        else if(n==6)
        {
            cout<<r-2<<" to "<<l-2<<'\n';
            cout<<r-5<<" to "<<r-2<<'\n';
            cout<<l+1<<" to "<<r-5<<'\n';
            cout<<r-6<<" to "<<l+1<<'\n';
            cout<<l-1<<" to "<<r-6<<'\n';
            cout<<r-1<<" to "<<l-1<<'\n';
        }
        else if(n==7)
        {
            cout<<r-2<<" to "<<l-2<<'\n';
            cout<<l+4<<" to "<<r-2<<'\n';
            cout<<r-6<<" to "<<l+4<<'\n';
            cout<<l+2<<" to "<<r-6<<'\n';
            cout<<r-5<<" to "<<l+2<<'\n';
            cout<<l-1<<" to "<<r-5<<'\n';
            cout<<r-1<<" to "<<l-1<<'\n';
        }
        return;
    }
    else
    {
        cout<<r-2<<" to "<<l-2<<'\n';
        cout<<l+2<<" to "<<r-2<<'\n';
        go(n-4,l+4,r-4);
        cout<<l-1<<" to "<<r-5<<'\n';
        cout<<r-1<<" to "<<l-1<<'\n';
        return;
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    go(n,1,2*n);
}