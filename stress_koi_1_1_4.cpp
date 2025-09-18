#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,b=0,c=0;
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=19;j++)
        {
            int temp=i*j;
            if(temp/100) a++;
            else if(temp/10) b++;
            else c++;
        }
    }
    cout<<a*3+b*2+c;
}