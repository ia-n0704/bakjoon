 
#include <bits/stdc++.h>
using namespace std;
int _VAL[6];

int compare (int _I, int _J) {
	if(_VAL[_I] < _VAL[_J]) return -1;
	if(_VAL[_I] > _VAL[_J]) return 1;
	return 0;
}

int five (int subtask) {
    int res[10];
	if(subtask==1)
    {
        int a,b,c,d;
        if(compare(2,3)==1)
        {
            a=2;
            b=3;
        }
        else
        {
            a=3;
            b=2;
        }
        if(compare(4,5)==1)
        {
            c=4;
            d=5;
        }
        else
        {
            c=5;
            d=4;
        }
        
        if(compare(a,c)==1)
            res[5]=a;
        else res[5]=c;
        
        int temp;
        if(res[5]==a)
        {
            if(compare(1,b)==1)
                temp=1;
            else temp=b;
            if(compare(temp,c)==1)
            {
                res[4]=temp;
                if(res[4]==1)
                {
                    if(compare(b,c)==1)
                        return b;
                    else
                        return c;
                }
                else
                {
                    if(compare(1,c)==1)
                        return 1;
                    else return c;
                }
            }
            else
            {
                res[4]=c;
                if(compare(temp,d)==1)
                    return temp;
                else return d;
            }
        }
        else
        {
            if(compare(1,d)==1)
                temp=1;
            else temp=d;
            if(compare(temp,a)==1)
            {
                res[4]=temp;
                if(res[4]==1)
                {
                    if(compare(a,d)==1)
                        return a;
                    else return d;
                }
                else
                {
                    if(compare(1,a)==1)
                        return 1;
                    else return a;
                }
            }
            else
            {
                res[4]=a;
                if(compare(temp,b)==1)
                    return temp;
                else return b;
            }
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
	int _T;
	scanf("%d", &_T);
	scanf("%d%d%d%d%d",&_VAL[1], &_VAL[2], &_VAL[3], &_VAL[4], &_VAL[5]);
	printf("%d\n", five(_T));
}