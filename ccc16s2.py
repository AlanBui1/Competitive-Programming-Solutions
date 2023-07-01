import sys; input = sys.stdin.readline

op = int(input())

n = int(input())

dmoj = [int(i) for i in input().split()]
peg = [int(i) for i in input().split()]

dmoj.sort()
peg.sort()
ans = 0
if op == 1:
    for i in range(n):
        ans += max(dmoj[i], peg[i])

else:
    dmoj.reverse()
    for i in range(n):
        ans += max(dmoj[i], peg[i])
        
print(ans)