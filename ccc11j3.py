num1 = int(input())
num2 = int(input())
ans = 0
while True:
  if num1-num2 <0:
    print(ans+2)
    break
  else:
    nxt = num1-num2
    num1=num2
    num2=nxt
    ans+=1