a, b, v = map(int, input().split())

d = a-b
import math
ans = math.ceil((v-a)/d)

print(ans+1)