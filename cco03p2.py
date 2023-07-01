import math
from math import gcd

c = int(input())

def sidelengths(wantlength, wantwidth, haslength, haswidth):
  length_wantlength = False
  length_wantwidth = False
  width_wantlength = False
  width_wantwidth = False

  if wantlength%haslength == 0:
    length_wantlength = True
  if wantlength%haswidth == 0:
    width_wantlength = True
  if wantwidth%haslength == 0:
    length_wantwidth = True
  if wantwidth%haswidth == 0:
    width_wantwidth = True

  if length_wantlength:
    rem = wantwidth - haswidth
    if rem%haswidth == 0: #or rem%haslength == 0:
      return True

  if length_wantwidth:
    rem = wantlength
    for i in range(wantlength//haswidth):
      rem -= haswidth
      if rem%haswidth == 0 or rem%haslength == 0:
        return True

  #if width_wantlength:
    #rem = wantwidth - haslength
   # if rem%haslength == 0:
  #    return True

  #if width_wantwidth:
   # rem = wantlength - haslength
    #if rem%haslength == 0:
     # return True

  return False


for q in range(c):
  numcards, length, width = map(int, input().split())
  listoffactors = []
  factor = gcd(length, width)
  new_len = length//factor
  new_width = width//factor
  minPer = 0
  if numcards == 1:
    print((2*length)+(2*width))
    continue
  if numcards%(new_width+new_len) == 0:
    larger = max(new_len, new_width)
    smaller = min(new_len, new_width)

    minPer += 2*smaller*larger*factor
    minPer += 2*(length+width)*numcards//(new_width+new_len)

  else:
    area = length*width*numcards
    for i in range(int(area**0.5), 0, -1):
      if area % i == 0:
        side1 = i
        side2 = area//i
        if sidelengths(side1, side2, length, width):
          minPer = (side1*2)+(side2*2)
          break

  print(minPer)