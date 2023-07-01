n = int(input())
arr = [int(k) for k in input().split()]
tot = sum(arr)
dpOld = [False for i in range(tot)]
dpNew = [False for i in range(tot)]
dpOld[0] = True

for i in range(n):
  for j in range(0, tot):
    dpNew[j] = dpOld[j]
    if j-arr[i] >= 0 and not dpNew[j]:
      dpNew[j] = dpOld[j-arr[i]]

  for j in range(tot):
    dpOld[j] = dpNew[j]

for i in range(tot//2, 0, -1):
  if dpNew[i]:
    ans = abs(tot-(2*i))
    break

print(ans)