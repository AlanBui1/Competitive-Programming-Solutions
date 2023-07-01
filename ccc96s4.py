n = int(input())
num = {'I':1,
  'V':5,
  'X':10,
  'L':50,
  'C':100,
  'D':500,
  'M':1000
   }

for i in range(n):
  word = input()
  r = [k for k in word]
  r.remove('=')
  r1 = ('').join(r[0:r.index('+')])
  r2 = ('').join(r[r.index('+')+1: ])
  x = 0
  for l in range(len(r1)):
    x += num[r1[l]]
    if r1[l:l+2] == 'IV':
      x -= 2
    elif r1[l:l+2] == 'IX':
      x -= 2
    elif r1[l:l+2] == 'XL':
      x -= 20
    elif r1[l:l+2] == 'XC':
      x -= 20
    elif r1[l:l+2] == 'CD':
      x -= 200
    elif r1[l:l+2] == 'CM':
      x -= 200
  for l in range(len(r2)):
    x += num[r2[l]]
    if r2[l:l+2] == 'IV':
      x -= 2
    elif r2[l:l+2] == 'IX':
      x -= 2
    elif r2[l:l+2] == 'XL':
      x -= 20
    elif r2[l:l+2] == 'XC':
      x -= 20
    elif r2[l:l+2] == 'CD':
      x -= 200
    elif r2[l:l+2] == 'CM':
      x -= 200
  while x > 0:
    if x > 1000:
      word = word+'CONCORDIA CUM VERITATE'
      x -= x
    if x == 1000:
      word = word+'M'
      x -= 1000
    elif x >= 900:
      word = word+'CM'
      x -= 900
    elif x >= 500:
      word = word+'D'
      x -= 500
    elif x >= 400:
      word = word+'CD'
      x -= 400
    elif x >= 100:
      word = word+'C'
      x -= 100
    elif x >= 90:
      word = word+'XC'
      x -= 90
    elif x >= 50:
      word = word+'L'
      x -= 50
    elif x >= 40:
      word = word+'XL'
      x -= 40
    elif x >= 10:
      word = word+'X'
      x -= 10
    elif x >= 9:
      word = word+'IX'
      x -= 9
    elif x >= 5:
      word = word+'V'
      x -= 5
    elif x >= 4:
      word = word+'IV'
      x -= 4
    elif x >= 1:
      word = word+'I'
      x -= 1
  print(word)