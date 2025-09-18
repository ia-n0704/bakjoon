#include <bits/stdc++.h>
using namespace std;
int main()
{
    string t[10]={"Never gonna give you up","Never gonna let you down","Never gonna run around and desert you","Never gonna make you cry","Never gonna say goodbye","Never gonna tell a lie and hurt you","Never gonna stop"};
    int n;
    cin>>n;
    cin.ignore();
    int flag=0;
    while(n--)
    {
        string s;
        getline(cin, s);
        int i;
        for(i=0;i<7;i++)
        {
            if(s==t[i])
            {
                break;
            }            
        }
        if(i==7)
        {
            cout<<"Yes";
            flag=1;
            break;
        }
    }
    if(!flag)
        cout<<"No";
}