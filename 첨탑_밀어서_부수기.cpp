#include <bits/stdc++.h>
using namespace std;
int arr[5000010];
int n;
int main()
{
    scanf("%d",&n);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>=arr[i-1]) res++;
    }
    printf("%d",res);
}