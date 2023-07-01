import math
ans = 0
a, b = map(int, input().split())
for i in range(max(0, a), b+1):
    
    S = int(math.sqrt(i))
    if S == math.sqrt(i):
        ans += 1
        
print(ans)