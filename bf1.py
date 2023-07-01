n = int(input())
lis = []
for i in range(n):
  x = int(input())
  lis.append(x)
while len(lis) >= 1:
  print(min(lis))
  lis.remove(min(lis))