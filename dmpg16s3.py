n, r, m = map(int, input().split())

rstps = {k:True for k in input().split()}
pstps = {k:True for k in input().split()}

rkt = 0
nom = 0

for i in pstps:
  if rkt >= m//2:
    nom = m-rkt
    break
  if i in rstps:
    rkt += 1
  else:
    nom += 1


ans1 = (rkt*(rkt+1))/2
ans2 = (nom*(nom+1))/2
print(int(ans1+ans2))