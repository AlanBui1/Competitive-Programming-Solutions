import sys
input = sys.stdin.readline

n, limit = map(int, input().split())
lis = []
for i in range(n):
  Pp, Vp, Pa, Va, Pg, Vg = map(int, input().split())
  lis.append([Pp, Vp, Pa, Va, Pg, Vg])

arr = [0 for i in range(limit+1)]
for Tpoor, Ppoor, Tavg, Pavg, Tgood, Pgood in lis:
  for i in range(limit, -1, -1):
    if i >= Tpoor:
      arr[i] = max(arr[i], arr[i-Tpoor]+Ppoor)
    if i>= Tavg:
      arr[i] = max(arr[i], arr[i-Tavg]+Pavg)
    if i>= Tgood:
      arr[i] = max(arr[i], arr[i-Tgood]+Pgood)

print(arr[limit])