#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a+d>b+c) cout<<"Persepolis";
    else if(a+d<b+c) cout<<"Esteghlal";
    else
    {
        if(b>d) cout<<"Esteghlal";
        else if(b<d) cout<<"Persepolis";
        else cout<<"Penalty";
    }
}