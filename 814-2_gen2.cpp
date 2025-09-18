#include <bits/stdc++.h>
using namespace std;
int cnt[15];
int main()
{
    srand(time(NULL));
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=14;j++)
        {
            while(1)
            {
                int num=rand()%10;
                if(cnt[num]<12)
                {
                    cout<<num;
                    cnt[num]++;
                    break;
                }                
            }
        }
        cout<<'\n';
    }
}