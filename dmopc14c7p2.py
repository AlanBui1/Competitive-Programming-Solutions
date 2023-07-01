n = int(input())
arr = [int(i) for i in input().split()]
m = min(arr)
M = max(arr)
ind = arr.index(m)
ind2 = arr.index(M)
flag = 0

for i in range(ind, ind2-1):
    if arr[i] >= arr[i+1]:
        flag = 1
        break

if flag or ind2 < ind:
    print("unknown")
else:
    print(M-m)