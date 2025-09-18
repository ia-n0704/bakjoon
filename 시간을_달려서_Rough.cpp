#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
미처 말하지 못했어
다만 디미고를 좋아했어
어린 날의 꿈처럼 마치 기적처럼
시간을 달려서 디미고생이 될 수만 있다면
선린고 속에서 손을 잡아줄게
*/

ll dimi_you,dimi_mod;
int main()
{
    cin>>dimi_you>>dimi_mod;
    ll dimi;
    ll dimi_better,than_sunrin;
    ll dimi_answer=1e18;
    while(dimi_you<=min((ll)1e12,dimi_mod)*(ll)2e6)
    {
        dimi_better=than_sunrin=0;
        for(dimi=1;;dimi<<=1)
        {
            if(dimi>dimi_you) break;
            if(dimi & dimi_you)
                dimi_better++;
            than_sunrin++;
        }
        dimi_answer=min(dimi_answer,dimi_better+than_sunrin-1);
        dimi_you+=dimi_mod;
    }
    cout<<dimi_answer;
}