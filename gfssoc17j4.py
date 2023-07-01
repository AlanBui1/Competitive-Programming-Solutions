n, c, m = map(int, input().split())
lis = []
lis2 = []
a= True
w = c
ans = 0
e = 0
for i in range(n):
  word = input()
  x = [k for k in word]
  x.reverse()
  space = x.index(' ')
  lis2.append(int(word[len(x)-space:]))
  lis.append(word[0:len(x)-space-1])
if len(lis) < c:
  a = False
for i in range(m):
  z = input()
  if z not in lis:
    a = False
  else:
    ans += int(lis2[(lis.index(z))])
    lis2[int(lis.index(z))] = 0
    c -= 1
lis2.sort(reverse = True)
if not a:
  print('Ace is dunzos')
else:
  for i in range(c):
    ans += int(lis2[i])
  e = str(ans/w)
  if len(e[e.index('.'): ]) < 3:
    print(e+'0')
  else:
    print(round((ans/w),2))