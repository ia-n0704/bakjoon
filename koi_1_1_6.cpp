#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt=0;
    for(int a=1;a<=3;a++)
    {
        for(int b=1;b<=3;b++)
        {
            for(int c=1;c<=3;c++)
            {
                for(int d=1;d<=3;d++)
                {
                    for(int e=1;e<=3;e++)
                    {
                        for(int f=1;f<=3;f++)
                        {
                            for(int g=1;g<=3;g++)
                            {
                                int x=0,y=0,z=0;
                                if(a==1) x++;
                                else if(a==2) y++;
                                else z++;
                                if(b==1) x++;
                                else if(b==2) y++;
                                else z++;
                                if(c==1) x++;
                                else if(c==2) y++;
                                else z++;
                                if(d==1) x++;
                                else if(d==2) y++;
                                else z++;
                                if(e==1) x++;
                                else if(e==2) y++;
                                else z++;
                                if(f==1) x++;
                                else if(f==2) y++;
                                else z++;
                                if(g==1) x++;
                                else if(g==2) y++;
                                else z++;
                                if(x>y) cnt++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
}