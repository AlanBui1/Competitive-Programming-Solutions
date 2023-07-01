import sys
input = sys.stdin.readline
from math import inf

for q in range(5):
    goal = int(input())
    n = int(input())
    coins = []
    for i in range(n):
        val = int(input())
        coins.append(val)

    lis = [inf for i in range(goal+1)]
    lis[0] = 0

    
    for coin in coins:
        for i in range(len(lis)):
            if lis[i] != inf:
                if i+coin < len(lis):
                    lis[i+coin] = min(lis[i+coin], lis[i]+1)

    print(lis[-1])