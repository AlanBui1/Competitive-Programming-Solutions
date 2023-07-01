n = int(input())
num = 0
lis = []
for i in range(n):
    m = int(input())
    lis.append(m)
lis.sort()
if len(lis) %2 == 1:
    print(lis[int(len(lis)/2)])
else:
  num = (lis[int(len(lis)/2)-1]+lis[int(len(lis)/2)])/2
  if num - int(num) > 0:
    print(int(num)+1)
  else:
    print(int(num))