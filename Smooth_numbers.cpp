#include <bits/stdc++.h>
using namespace std;
string s[100]={
    "",
    "9",
    "99",
    "989",
    "9889",
    "97679",
    "976679",
    "9643469",
    "96433469",
    "",
};
int main()
{
    int l;
    cin>>l;
    if(l>8) cout<<-1;
    else cout<<s[l];
}