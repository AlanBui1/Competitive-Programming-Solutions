n = int(input())
m = int(input())
lis = []
lis2 = []
for i in range(n):
  word = input()
  lis.append(word)
for i in range(m):
  word = input()
  lis2.append(word)

for k in range(0,m):
  for i in range(0,n):
    print(lis[i],'as',lis2[k])