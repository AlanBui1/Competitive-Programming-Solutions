n = int(input())
for a in range(n):
  lis1 = []
  lis2 = []
  lis3 = []
  s = int(input())
  v = int(input())
  o = int(input())
  for i in range(s):
    subject = input()
    lis1.append(subject)
  for i in range(v):
    verb = input()
    lis2.append(verb)
  for i in range(o):
    objec = input()
    lis3.append(objec)
  for i in range(s):
    for k in range(v):
      for j in range(o):
        print(lis1[i], lis2[k], lis3[j]+'.')