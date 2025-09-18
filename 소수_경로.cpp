#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
long long ch[10010];
int prime[10010];
int main()
{
    prime[1]=1;
    for(int i=2;i<=9999;i++)
    {
        if(prime[i]) continue;
        for(int j=2;i*j<=9999;j++)
        {
            prime[i*j]=1;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        queue<pair<int,long long>> q;
        q.push({a,0});
        long long res=1e16;
        fill(ch,ch+10000,0);
        while(!q.empty())
        {
           
            int num=q.front().x;
            long long cnt=q.front().y;
            //cout<<num<<'\n';
            ch[num]=1;
            if(num==b)
            {
                cout<<cnt<<'\n';
                break;
            }            
            q.pop();
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    if(i==0 && j==0) continue;
                    string s=to_string(num);
                    s[i]=j+'0';
                    int temp=stoi(s);
                    //cout<<temp<<'\n';
                    if(ch[temp]==0 && prime[temp]==0)
                    {
                        //cout<<temp<<'\n';
                        q.push({temp,cnt+1});
                    }
                        
                }
            }
        }
    }
}