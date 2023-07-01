n = int(input())
t = 0
s = 0
for i in range(n):
  word = input()
  t += word.count('t') + word.count('T')
  s += word.count('s') + word.count('S')
if s >= t:
  print('French')
else:
  print('English')