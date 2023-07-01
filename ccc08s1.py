a = True
t = 201
while a == True:
  city = [k for k in input().split()]
  if city[0] == 'Waterloo':
    a = False
    continue
  if int(city[1]) < t:
    t = int(city[1])
    c = city[0]
  
print(c)