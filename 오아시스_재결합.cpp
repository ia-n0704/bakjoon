#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    long long res=0;
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int cnt=0;
        int num=1;
        while(!s.empty())
        {
            if(s.top().first<=a)
            {
                cnt+=s.top().second;
                if(s.top().first==a)
                    num+=s.top().second;
                s.pop();
            }
            else break;
        }
        if(!s.empty()) cnt++;
        //cout<<cnt<<" ";
        res+=cnt;
        s.push({a,num});
    }
    cout<<res;
}
//1 2 1 1 1 4 1 2 2 4 1 1 2