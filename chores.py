import sys;
input = sys.stdin.readline
MOD = int(1e9)+7

n = int(input())

lis = []

for i in range(n):
    a, b = map(int, input().split())
    lis.append([a,b])

lis.sort()

prev = 0

tim = 0

for val, cnt in lis:
    
    prev += tim*cnt
    prev %= MOD

    prev += (cnt)*(cnt+1)//2*val
    prev %= MOD

    tim += val*cnt
    tim %= MOD

print(prev)