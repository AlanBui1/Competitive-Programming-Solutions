win = 0
s = 1
while win != 100:
  num = int(input())
  if num == 0:
    print('You Quit!')
    break
  s+=num
  if s > 100:
    s-=num
  elif s == 9:
    s = 34
  elif s == 40:
    s = 64
  elif s == 67:
    s = 86
  elif s == 54:
    s = 19
  elif s == 90:
    s = 48
  elif s == 99:
    s = 77
  print('You are now on square',str(s))
  if s == 100:
    print('You Win!')
    break