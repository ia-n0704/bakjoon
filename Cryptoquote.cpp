#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[1010],b[1010];
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        cin.getline(a,1010);
        cin.getline(b,1010);
        //cin>>b;
        //cout<<a;
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]<'A' || a[i]>'Z') cout<<a[i];
            else cout<<b[a[i]-'A'];
        }
        cout<<'\n';
    }
}