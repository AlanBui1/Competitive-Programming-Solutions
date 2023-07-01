import sys
input = sys.stdin.readline

N = int(input())
T = int(input())

pumpkins = [int(input()) for i in range(N)]
pumpkins.sort()
left = []
right = [0]

for i in pumpkins:
    if i < 0:
        left.append(abs(i))
    else:
        right.append(abs(i))

left.reverse()
left = [0] + left

ans = int(1e9)
r = len(right)
for i in range(len(left)):
    #print(i, left[i] + right[T-i])
    if r > T - i >= 0:
        ans = min(ans, min(left[i]*2 + right[T-i], right[T-i]*2 + left[i]))

print(ans)