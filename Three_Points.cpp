#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<double,double> a,b,c;
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
    printf("%.15lf",(double)sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second))+2*(double)sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second)));
}