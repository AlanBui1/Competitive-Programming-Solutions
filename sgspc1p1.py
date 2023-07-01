import sys
input = sys.stdin.readline

def subSum(n, lis, x):
    ret = 0
    for i in range(n):
        ret += times[i]*(x^lis[i])
    return ret

n = int(input())
arr = [int(i) for i in input().split()]
times = [0 for i in range(n)]

for i in range(n):
    if times[i] != 0:
        break

    times[i] = n-(2*i)
    times[n-i-1] = n-(2*i)
    if i != 0:
        times[i] += times[i-1]
        if i != n-i-1:
            times[n-i-1] += times[n-i]
            
ans = 0
curSum = subSum(n, arr, 0)

for i in range(34):        
    val = subSum(n, arr, (1 << i))
    
    if val < curSum:
        ans |= (1 << i)
    

print(ans)