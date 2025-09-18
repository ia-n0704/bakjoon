#include "WAEP.h"
#include <bits/stdc++.h>
using namespace std;
int janken(int p)
{
    if(p==0) return 5;
    else if(p==2) return 2;
    else return 0;
}
void init(int t)
{
    int p;
    while(t--)
    {
        scanf("%d",&p);
        printf("%d\n",janken(p));        
    }
}