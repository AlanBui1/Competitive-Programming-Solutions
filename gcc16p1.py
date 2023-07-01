import sys; input =sys.stdin.readline

n, a,c  =map(int, input().split())
cnt =0
conv = {}
rconv = {}
inf = int(1e9)
adds = []
bad = []
nums = []

for i in range(a+c):
    lis = [int(k) for k in input().split()]
    nums.append(lis[0])
    nums.append(lis[1])
    lis[1] += 1
    nums.append(lis[1])
    nums.append(lis[1]-2)

    if i >= a:
        bad.append(lis)
    else:
        adds.append(lis)
nums.sort()
conv[nums[0]] = 0
rconv[0]= nums[0]
cnt+=1
for i in range(1, len(nums)):
    if nums[i] == nums[i-1]:
        continue
    if nums[i] not in conv:
        conv[nums[i]] = cnt
        rconv[cnt] = nums[i]
        cnt+= 1

arr = [0 for i in range(cnt)]

for a, b in adds:
    arr[conv[a]] += 1
    arr[conv[b]] -= 1

for a, b in bad:
    arr[conv[a]]  -= inf
    arr[conv[b]]  += inf

for i in range(1, len(arr)):
    arr[i] += arr[i-1]


ans = 0

for i in range(len(arr)):
    if arr[i] > 0:
        ans += rconv[i+1] - rconv[i]

    

print(ans)