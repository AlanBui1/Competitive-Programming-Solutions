k = int(input())

lis = [0]+[i*(i-1)//2 for i in range(1, 5000)]
ans = []

while k > 0:    
    lo = 0
    hi = 4999
    best = -1

    while lo <= hi:
        mid = (lo+hi)//2

        if lis[mid] <= k:
            best = max(best, mid)
            lo = mid+1
        else:
            hi = mid-1

    ans.append(best)
    k -= lis[best]

need = 0
for i in ans:
    if i == 1:
        need += 2
    else:
        need += i

cur = 1
group = []
print(need, len(ans)+need-1)

for cycleLen in ans:
    for i in range(cycleLen):
        print(cur+i, cur+(i+1)%cycleLen)

    group.append(cur)
    cur += cycleLen

for i in range(len(group)-1):
    print(group[i], group[i+1])