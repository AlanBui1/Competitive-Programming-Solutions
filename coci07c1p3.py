import sys
input = sys.stdin.readline

n = int(input())
kids = [int(i) for i in input().split()]
kids.sort()
L, R = map(int, input().split())

diff = int(1e10)
ans = -1

smallest = L
if L%2 == 0:
    smallest = L+1

highest = R
if R%2 == 0:
    highest = R-1

ans = smallest
for i in range(n):
    diff = min(diff, abs(smallest-kids[i]))

D = int(1e10)
for i in range(n):
    D = min(D, abs(highest-kids[i]))

if D > diff:
    diff = D
    ans = highest

for i in range(n-1):
    mid = (kids[i]+kids[i+1])//2
    if L <= mid <= R:
        if kids[i+1]-mid > diff:
            diff = kids[i+1]-mid
            ans = mid

if ans%2 == 0:
    ans -= 1
print(ans)