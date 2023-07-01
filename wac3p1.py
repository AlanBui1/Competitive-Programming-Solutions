import sys; input = sys.stdin.readline

t, d, p = map(float, input().split())
cnt = 0
if t < -40:
    cnt += 1
if d >= 15:
    cnt += 1
if p > 50:
    cnt += 1
    
if cnt >= 2:
    print("YES")
else:
    print("NO")