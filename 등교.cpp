#import<iostream>
int a,b,c,x,t=-1;main(){std::cin>>a>>x;while(a--){std::cin>>b>>c;c+=b;(c<=x&&b>t)?t=b:0;}std::cout<<t;}