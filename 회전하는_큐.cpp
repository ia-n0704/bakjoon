#include<stdio.h>
int arr[100];
int question[100];
int main()
{
    int n,m,res=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&question[i]);
    for(int i=1;i<=n;i++)
        arr[i]=i;
    int st=1;
    for(int i=1;i<=m;i++)
    {
        int idx;
        int temp;
        for(int j=st;j<=n;j++)
        {
            if(arr[j]==question[i])
            {
                idx=j;
                break;
            }
        }
        if(idx-st>n-idx+1) res+=n-idx+1;
        else res+=idx-st;
        while(1)
        {
            if(arr[st]==question[i]) break;
            temp=arr[st];
            for(int k=st;k<n;k++)
                arr[k]=arr[k+1];
            arr[n]=temp;
        }
        st++;
    }
    printf("%d",res);
}