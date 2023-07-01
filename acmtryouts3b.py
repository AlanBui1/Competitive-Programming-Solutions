n = int(input())
x = '<3'
for i in range(n):
  word = input()
  num =word.count('<3')
  for k in range(num):
    x = x+' <3'
  print(x)
  x = '<3'
  num = 0