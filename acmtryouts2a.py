n = int(input())
lvl = ''
num = 0
for i in range(n):
  lvl = input().split('-')
  world = int(lvl[0])
  l = int(lvl[1])
  while world <= 8:
    num += 1
    if world == 1:
      if l == 2:
        world = 4
        l = 1
        num +=1
    if world == 4:
      if l == 2:
        world = 8
        l = 1
        num +=1
    if l > 4:
      world += 1
      l = 1
    l += 1
  print(num -1)
  num = 0