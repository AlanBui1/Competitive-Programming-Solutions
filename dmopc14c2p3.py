n = int(input())
e = [int(k) for k in input().split()]
log  = [int(l) for l in input().split()]
e.sort(reverse = True)
log.sort()
x=0
if max(e) == 1:
  print(sum(log))
else:
  for i in range(n):
    x += (e[i]*log[i])
  print(x)