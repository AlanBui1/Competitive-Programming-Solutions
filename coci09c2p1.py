a, i = map(int, input().split())
cur = 0
from math import ceil
while True:
    cur += 1
    if ceil(cur/a) == i:
        print(cur)
        break