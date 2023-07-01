w = int(input())
h = int(input())
x = 0
y = 0
twoD = [["1" for k in range(w)]for i in range(h)]
b = ''

for y in range(0,h,1):
  if y%2 == 1:
    x = 1
  else:
    x = 0
  while x < w:
    twoD[y][x] = '0' 
    x = x + 2
  
for y in range(h): 
  for i in range(w):
    b = b + twoD[y][i]
  print(b)
  b = ''