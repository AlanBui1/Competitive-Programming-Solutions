n = int(input())
a =[int(k) for k in input().split()]
b =[int(k) for k in input().split()]
war = 0
num = 0
for i in range(n):
  if a[i] != b[i]:
    num = 0
  elif a[i] == b [i]:
    war += 1
    num += 1
    if num == 2:
      war-=1
      num=1
      
print(war)