#include <bits/stdc++.h>
using namespace std;
double k,w,l;
int main()
{
    cin>>k>>w>>l;
    printf("%.6lf",atan(l/((pow(2,k)-1)*3*(w/2)))*180/M_PI);
}