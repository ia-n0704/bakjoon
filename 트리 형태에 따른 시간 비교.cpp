#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    clock_t st=clock();

    queue<long long> q;
    q.push(1);
    while(!q.empty())
    {
        long long a=q.front();
        q.pop();
        if(a==n/10*2) cout<<"20% 완료"<<'\n';
        if(a==n/10*4) cout<<"40% 완료"<<'\n';
        if(a==n/10*6) cout<<"60% 완료"<<'\n';
        if(a==n/10*8) cout<<"80% 완료"<<'\n';
        if(a==n) cout<<"100% 완료!!"<<'\n';
        if(a==n) break;
        q.push(a+1);
    }
    clock_t en=clock();
    cout<<"일자형 트리의 최종 전파 속도의 최댓값은 ";
    cout<<double(en-st)/CLOCKS_PER_SEC;
    cout<<"초 입니다.\n";
    q.push(1);
    clock_t st2=clock();
    while(!q.empty())
    {
        long long a=q.front();
        //cout<<a<<'\n';
        q.pop();
        if(a*k>n) break;
        q.push(a*k);
    }
    clock_t en2=clock();
    cout<<"완전 n진 트리의 최종 전파 속도의 최댓값은 ";
    cout<<double(en2-st2)/CLOCKS_PER_SEC;
    cout<<"초 입니다.\n";
}
