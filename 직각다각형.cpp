#include <bits/stdc++.h>        //직각다각형
using namespace std;
int X[1000010],Y[1000010],A[100010],B[100010],amx,bmx,res,mx;
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&A[i],&B[i]);
        A[i]+=500000;
        B[i]+=500000;
        if(amx<A[i])
            amx=A[i];
        if(bmx<B[i])
            bmx=B[i];
    }
    A[i]=A[1];
    B[i]=B[1];
    for(i=1;i<=n;i++)
    {
        if(A[i]==A[i+1])
        {
            Y[min(B[i],B[i+1])]++;
            Y[max(B[i],B[i+1])]--;
        }
        else
        {
            X[min(A[i],A[i+1])]++;
            X[max(A[i],A[i+1])]--;
        }
    }
    for(i=0;i<=amx;i++)
    {
        res+=X[i];
        if(mx<res)
            mx=res;
    }
    res=0;
    for(i=0;i<=bmx;i++)
    {
        res+=Y[i];
        if(mx<res)
            mx=res;
    }
    printf("%d",mx);
}