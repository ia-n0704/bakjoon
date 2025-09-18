#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
        else 
        {
            int sum=0;
            for(int i=1;i<=n;i++)
                sum+=i;
            printf("%d\n",sum);
        }
    }
}