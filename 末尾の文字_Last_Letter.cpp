#import<iostream>
int main(){std::string s;int n;std::cin>>n>>s;s[n-1]=='G'?s.erase(n-1):s+='G';std::cout<<s;}