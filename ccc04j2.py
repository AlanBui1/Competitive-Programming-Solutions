x = int(input())
y = int(input())
print('All positions change in year',x)
while x < y:
  x+=60
  if x> y:
    break
  print('All positions change in year',x)