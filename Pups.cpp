#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        double d,f,p;
        cin>>d>>f>>p;
        double cost=d*f*p;
        printf("$%.2lf\n",cost);
    }
}