#include <bits/stdc++.h>
using namespace std;
string s[4]={"윤예진","남송연","이기원","노재원"};
int main()
{
    srand(time(NULL));
    for(int i=1;i<=4;i++)
    {
        int a=rand()%4;
        cout<<s[i-1]<<" -> "<<s[a]<<'\n';
    }
}