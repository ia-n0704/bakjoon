#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res[1100000];
void sol(int l,int r,int num)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //printf("%d %d %d\n",l,r,num);
    if(r-l+1<=num)
    {
        if(l==r) res[l]=2;
        else res[l]=res[r]=1;
        return;
    }
    if(l==r)
        return;
    /*int lnum,rnum;
    if(num%2)
    {
        lnum=num/2+1;
        rnum=num/2;
    }
    else
    {
        lnum=num/2+1;
        rnum=num/2-1;
    }*/
    int mid=(l+r)/2;
    int temp=(mid-l+1)/2;
    int a=max(temp,num-(mid-l+1));
    if(mid-l+1>=num)
    {
        sol(l,mid,num);
    }
    else
    {
        sol(l,mid,num-a);
        sol(mid+1,r,a);
    }
}
int main()
{
    int n;
    cin>>n;
    int right=1;
    while(right<n) right*=2;
    sol(1,right,n);
    int temp=0;
    int print=0;
    for(int i=1;i<=right;i++)
    {
        if((res[i]==1 && temp==1) || res[i]==2)
        {
            print=-1;
            temp=0;
        }
        else if(res[i]==1 && temp==0)
        {
            print=1;
            temp=1;
        }
        if(print==-1)
        {
            cout<<'#';
            print=0;
        }
        else if(print==1)
            cout<<'#';
        else
            cout<<'.';
    }
}
