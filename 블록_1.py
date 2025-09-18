#dp[i]=n*i 모양을 만드는 경우의 수
#dp[0]=dp[1]=1
#dp[i]=dp[i-1]+dp[i-2]+...+dp[0]=2^(i-1)(1<=i<n)
#dp[n]=dp[n-1]+dp[n-2]+...+dp[0]+dp[n-1]+dp[n-2]+...dp[1]
#dp[n]=2^n-1
#dp[i]=dp[i-1]+dp[i-2]+....+d*dp[i-n]
#d=dp[n-1]+dp[n-2]+.....+dp[0]=2^(n-1)
dp=[1]*10001
N, M=map(int, input().split())
for i in range(2, N):
    dp[i]=dp[i-1]*2%1999
dp[N]=(4*dp[N-1]-1)%1999
c=[1]*N+[dp[N-1]*2]
if M<=N:
    print(dp[M])
    exit(0)
for i in range(N+1, M+1):
    dp[i]=0
    for j in range(1, N+1):
        dp[i]=(dp[i]+dp[i-j]*c[j])%1999
print(c[N])