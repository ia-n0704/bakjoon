#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int c[110];
int main()
{
    cin>>t;
    while(t--)
    {
        int res=0;
        int three=0,five=0,seven=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            if(c[i]==3) three++;
            else if(c[i]==5) five++;
            else seven++;
        }
        for(int i=0;i<=5;i++)
        {
            if(i*3>three) break;
            int x=three,y=five,z=seven;
            x-=i*3;
            int time=i;
            int num=i*3;
            while(x && z && time<5) //three and seven
            {
                x--;
                z--;
                time++;
                num+=2;
            }
            while(y>=2 && time<5)   //two fives
            {
                y-=2;
                time++;
                num+=2;
            }
            while(x>=2 && time<5)   //two threes
            {
                x-=2;
                time++;
                num+=2;
            }
            while(x && y && time<5) //three and five
            {
                x--;
                y--;
                time++;
                num+=2;
            }
            num+=max(0,min(x+y+z,5-time));
            res=max(num,res);
        }
        cout<<res<<'\n';
    }
}