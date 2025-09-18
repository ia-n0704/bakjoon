#include <bits/stdc++.h>
#include "testlib.h"
struct dimi
{
    int dream,passion,share;
    int sum;
};
dimi _inf[100010];
using namespace std;
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int ans_num,ouf_num=0;
    vector<int> _ans,_ouf;
    while (!ans.seekEof() && !ouf.seekEof())
    {
        int a=ans.readInt(1,100'000,"a");
        _ans.push_back(a);
    }
    while (!ouf.seekEof())
    {
        int a=ouf.readInt(1,100'000,"a");
        _ouf.push_back(a);
    }
    int n=inf.readInt(1,100'000,"n");
    int m=inf.readInt(1,n,"m");
    int a=inf.readInt(1,100'000'000,"a");
    int b=inf.readInt(1,100'000'000,"b");
    int c=inf.readInt(1,100'000'000,"c");
    dimi st={a,b,c,a+b+c};
    for(int i=1;i<=n;i++)
    {
        a=inf.readInt(1,100'000'000,"a");
        b=inf.readInt(1,100'000'000,"b");
        c=inf.readInt(1,100'000'000,"c");
        _inf[i]={a,b,c,a+b+c};
    }
    for(int i=0;i<_ouf.size();i++)
    {
        if(_inf[_ouf[i]].sum>st.sum)
            quitf(_wa,"%d student's sum is bigger than jaewon's sum",_ouf[i]);
        ouf_num+=_inf[_ouf[i]].sum;
    }
    for(int i=0;i<_ans.size();i++)
        ans_num+=_inf[_ans[i]].sum;
    if(ouf_num==ans_num)
        quitf(_ok, "%d number(s)", _ouf.size());
    else quitf(_wa,"answer is incorrect [answer : %d, output : %d]",ans_num,ouf_num);
}