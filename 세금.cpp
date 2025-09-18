#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    cout<<n-(n/100*22)<<" ";
    cout<<(n/100*80)+(n/100*20)-((n/100*20)/100*22);
}