x = 0
num = {'I':1,
  'V':5,
  'X':10,
  'L':50,
  'C':100,
  'D':500,
  'M':1000
   }

for i in range(5):
  r = input()
  if r[len(r)-2: ] == 'IX' or r[len(r)-2: ] == 'IV':
    x -= 2
  for j in range(len(r)):
    if r[j:j+2] == 'CM':
      x -= 200 
    elif r[j:j+2] == 'XL':
      x -= 20
    elif r[j:j+2] == 'XD':
      x -= 20
    elif r[j:j+2] == 'XM':
      x -= 20
    elif r[j:j+2] == 'CD':
      x -= 200
    elif r[j:j+2] == 'XC':
      x -= 20
    elif r[j:j+2] == 'IL':
      x -= 2
    elif r[j:j+2] == 'IC':
      x -= 2
    elif r[j:j+2] == 'ID':
      x-= 2
    elif r[j:j+2] == 'IM':
      x -= 2
    elif r[j:j+2] == 'VM':
      x -= 10
    elif r[j:j+2] == 'VD':
      x -= 10
    elif r[j:j+2] == 'VC':
      x -= 10
    elif r[j:j+2] == 'VL':
      x -= 10
    elif r[j:j+2] == 'LD':
      x -= 100
    elif r[j:j+2] == 'LM':
      x -= 100
      
  for k in range(len(r)):
    x += num[r[k]]
  print(x)
  x=0