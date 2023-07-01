n = int(input())
for i in range(n):
  s1, s2, s3 = map(int, input().split())
  lis = [s1, s2, s3]
  lis.sort()
  if lis[0]**2+lis[1]**2 == lis[2]**2:
    print("R")
  elif lis[0]**2+lis[1]**2 <lis[2]**2:
    print("O")
  else:
    print("A")