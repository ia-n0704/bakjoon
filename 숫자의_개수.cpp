#import<iostream>
int a,b,c,d,cnt[11];main(){std::cin>>a>>b>>c;a*=b*c;while(a){cnt[a%10]++;a/=10;}while(d<=9) std::cout<<cnt[d++]<<'\n';}