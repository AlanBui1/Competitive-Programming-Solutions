import math

c = int(input())
r, w, b, y, g = map(int, input().split())

ans = math.ceil(r/4) + math.ceil(w/5) + math.ceil(b/4) + math.ceil(y/3) + math.ceil(g/6)

print(max(0, c-ans))