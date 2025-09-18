#include <bits/stdc++.h>
using namespace std;
int arr[200010];
int ch[200010];
int n;
bool check()
{
    int cur=1;
    while(1)
    {
        if(ch[cur]) break;
        ch[cur]=1;
        cur=arr[cur]*cur%n;
        if(cur==0) cur=n;
    }
    int flag=0;
    for(int i=1;i<=n;i++)
        if(!ch[i]) flag=1;
    return flag;
}
int main()
{
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        n=i;
        iota(arr+1,arr+n+1,1);
        do
        {
            if(!check())
            {
                for(int i=1;i<=n;i++)
                    cout<<arr[i]<<" ";
                cout<<'\n';
            }
            fill(ch,ch+n+1,0);
        }while(next_permutation(arr+1,arr+n+1));     
        cout<<'\n';   
    }

}