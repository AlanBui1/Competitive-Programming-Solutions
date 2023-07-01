import sys
input = sys.stdin.readline
lines = {}
check = {}

n = int(input())
flag = 0
for i in range(n):
    m, b = map(int, input().split())
    if flag:
        continue

    if m not in lines:
        lines[m] = []
    if (m, b) in check:
        flag = 1
    lines[m].append(b)
    check[(m, b)] = 1
    
if flag:
    print("Infinity")
    
else:
    ans = n*(n-1)//2
    for slope in lines:
        leng = len(lines[slope])
        ans -= leng*(leng-1)//2

    print(ans)