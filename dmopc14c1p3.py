n = int(input())
num=0
for i in range(n):
  g = int(input())
  num += g
s = int(input())
for i in range(1,s+1):
  new = int(input())
  num+=new
  a = round(num/(n+i),3)
  print(a)