n = int(input())
ans = 0
while n > 1:
  lim = n**0.5
  factor = 2
  while factor <= lim:
    if n%factor == 0:
      break
    factor+=1

  if n%factor != 0:
    ans += n-1
    n -= 1

  else:
    ans += (n-(n/factor))/(n/factor)
    n -= n/factor

print(int(ans))