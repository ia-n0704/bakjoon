a=1
b=1
idx=3
while True:
  c=a+b
  a=b
  b=c
  idx+=1
  cnt=0
  while c:
    c//=10
    cnt+=1
  if cnt>=2:
    break
print(idx)