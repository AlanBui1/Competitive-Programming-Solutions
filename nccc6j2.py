s = input()
x = 0
name = 'pusheen'
for i in range(7):
  if s[i] != name[i]:
    x+=1
print(x)