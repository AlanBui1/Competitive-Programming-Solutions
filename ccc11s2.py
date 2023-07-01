n = int(input())
lis = []

x=0
for i in range(n):
  lis.append(input())
for i in range(n):
  ans = input()
  if ans == lis[i]:
    x+=1
print(x)