#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int st[300010],s,e;
void push(int x)
{
    st[e++]=x;
}
int pop()
{
    if(s==e) return -1;
    return st[s++];
}
int back()
{
    if(s==e) return -1;
    return st[e-1];
}
int front()
{
    if(s==e) return -1;
    return st[s];
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        char s[10];
        int a;
        scanf("%s",s);
        if(strcmp(s,"PUSH")==0)
        {
            scanf("%d",&a);
            push(a);
        }
        else if(strcmp(s,"FRONT")==0) printf("%d\n",front());
        else if(strcmp(s,"POP")==0) printf("%d\n",pop());
        else printf("%d\n",back());
    }
    printf("%d\n",e-s);
    for(int i=s;i<e;i++) printf("%d ",st[i]);
}