learning_rate,n,stnum=map(float,input().split())
for i in range(n):
	temp=stnum*15-45
	print(f"i={i} | {temp} {stnum-learning_rate*temp}")
	stnum=stnum-0.1*temp