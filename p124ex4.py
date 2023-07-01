import math
p = float(input())
start = int(input())
n = int(input())
finish = int(input())


for i in range(finish-start):
    n *= p/100 +1

print(math.ceil(n))