#include <bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=1;i<=200;i++)
    {
        int sum=0;
        for(int j=i;j<=200;j++)
        {
            if(j==10) continue;
            sum+=j;
            if(sum>=200 && sum<=208 && sum%2==0) cout<<i<<" "<<j<<" | "<<sum<<'\n';
            if(sum>208) break;
        }
    }
}