import sys;
input = sys.stdin.readline

n = int(input())
lis = [i[0].upper() for i in input().split()]

ans = 0

prev = ""
cur = 0

MOD = int(1e9)+7

for i in range(n):
    if prev == lis[i]:
        ans += cur
        cur += 1
    else:
        cur = 1
        prev = lis[i]
    ans += 1
    ans %= MOD
    
print(ans)