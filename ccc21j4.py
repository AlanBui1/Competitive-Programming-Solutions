books = [k for k in input()]
l = books.count('L')
m = books.count('M')
s = books.count('S')

large = books[0:l]
medium = books[l:m+l]
small = books[m+l: ]

lm = large.count("M")
ls = large.count("S")

ml = medium.count("L")
ms = medium.count("S")

sl = small.count("L")
sm = small.count("M")

ans = 0
while lm+ls+ml+ms+sl+sm > 0:
  if ls > 0 and sl > 0:
    while ls > 0 and sl > 0:
      ls -= 1
      sl -= 1
      ans += 1

  elif lm > 0 and ml > 0:
    while lm > 0 and ml > 0:
      lm -= 1
      ml -= 1
      ans +=1

  elif ms > 0 and sm > 0:
    while ms > 0 and sm > 0:
      ms -= 1
      sm -= 1
      ans += 1

  elif lm > 0 and ms > 0 and sm > 0:
    while lm > 0 and ms > 0 and sm > 0:
      lm -= 1
      ms -= 1
      sm -= 1
      ans += 2

  elif ls > 0 and sm > 0 and ml > 0:
    while ls > 0 and sm > 0 and ml > 0:
      ls -= 1
      sm -= 1
      ml -= 1
      ans +=2

  elif sl > 0 and lm > 0 and ms > 0:
    while sl > 0 and lm > 0 and ms > 0:
      sl -= 1
      lm -= 1
      ms -= 1
      ans += 2

print(ans)