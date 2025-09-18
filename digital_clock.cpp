#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,s;
    int res_second=0;
    for(h=0;h<24;h++)
    {
        if(h%10==1 || h/10==1)
        {
            res_second+=60*60;
            continue;
        }
        for(m=0;m<60;m++)
        {
            if(m%10==1 || m/10==1)
            {
                res_second+=60;
                continue;
            }
            for(s=0;s<60;s++)
                if(s%10==1 || s/10==1)
                    res_second+=1;
        }
    }
    cout<<"디지털 시계에서 하루 동안 숫자 1을 볼 수 있는 시간은 "<<res_second<<"초입니다.";
}