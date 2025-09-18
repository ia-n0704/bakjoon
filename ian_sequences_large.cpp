#include <bits/stdc++.h>
using namespace std;
int ans[200010];
void go(int l,int r,int num,int k)
{
    if(num<=k)      //k보다 작거나 같은 경우 처리
    {
        int temp=1;
        for(int i=l;i<=r;i+=2)
        {
            ans[i]=temp;
            ans[i+1]=temp;
            temp++;
        }
        return;
    }

    int tidx=l+k;
    for(int i=0;i<k;i++)        //1번 경우
    {
        if(num-i<=k)
        {
            tidx=l+i;
            break;
        }
        ans[l+i]=num-i;
    }
    if(num<2*k)         //2k보다 작은 경우 따로 처리
    {
        int idx=tidx;
        for(int i=num-k+1;i<=k;i++)
        {
            ans[idx]=i;
            ans[idx+1]=i;
            idx+=2;
        }
    }
    else
        go(l+k,l+2*num-3*k-1,num-2*k,k);        //2번 경우

    for(int i=0;i<k;i++)        //3번 경우
    {
        if(num-i<=k) break;
        int idx=r-1-i*3;
        ans[idx-1]=num-k-i;
        ans[idx]=num-i;
        ans[idx+1]=num-k-i;
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    go(1,2*n,n,k);
    for(int i=1;i<=2*n;i++) cout<<ans[i]<<" ";
}