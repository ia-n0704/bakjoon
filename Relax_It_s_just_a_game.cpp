#import<iostream>
int n,m;int main(){while(1){std::cin>>n>>m;if(n<0)break;printf("%d+%d%s%d\n",n,m,n-1&&m-1?"!=":"=",n+m);}}