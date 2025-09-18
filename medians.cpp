#include <bits/stdc++.h>
using namespace std;
int arr[100010];
int res[200010];
int ch[200010];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int mn=1,mx=2*n-1;
    res[1]=arr[1];
    ch[arr[1]]=1;
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            while(ch[mn]) mn++;
            res[i*2-2]=mn;
            ch[res[i*2-2]]=1;
            while(ch[mx]) mx--;
            res[i*2-1]=mx;
            ch[res[i*2-1]]=1;
        }
        else if(arr[i]>arr[i-1])
        {
            if(ch[arr[i]])
            {
                while(ch[mx]) mx--;
                res[i*2-2]=mx;
                ch[res[i*2-2]]=1;
                while(ch[mx]) mx--;
                res[i*2-1]=mx;
                ch[res[i*2-1]]=1;
            }
            else
            {
                res[i*2-2]=arr[i];
                ch[res[i*2-2]]=1;
                while(ch[mx]) mx--;
                res[i*2-1]=mx;
                ch[res[i*2-1]]=1;
            }
        }
        else
        {
            if(ch[arr[i]])
            {
                while(ch[mn]) mn++;
                res[i*2-2]=mn;
                ch[res[i*2-2]]=1;
                while(ch[mn]) mn++;
                res[i*2-1]=mn;
                ch[res[i*2-1]]=1;
            }
            else
            {
                res[i*2-2]=arr[i];
                ch[res[i*2-2]]=1;
                while(ch[mn]) mn++;
                res[i*2-1]=mn;
                ch[res[i*2-1]]=1;
            }
        }
    }
    for(int i=1;i<=2*n-1;i++) cout<<res[i]<<" ";
}