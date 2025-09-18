#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1010];
int b[1010];
void tree(int mid,int l,int r)
{
    for(int i=l;i<r;i++)
    {
        if(a[mid]==b[i])
        {
            tree(mid+1,l,i);
            tree(mid+i+1-l,i+1,r);
            printf("%d ",a[mid]);
            break;
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        tree(0,0,n);
        printf("\n");
    }
}