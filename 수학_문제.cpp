#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a=n;
        if(n%9!=0)
        {
            cout<<-1<<" ";
            continue;
        }
        int temp=999999999;
        int num=0;
        int res;
        while(temp)
        {
            if(9<(a/temp))
            {
                res=-1;
                break;
            }
            num=(num+a/temp)*10;
            a%=temp;
            temp/=10;
        }
        if(res==-1) cout<<-1;
        else cout<<num;
        cout<<" ";
    }
}
