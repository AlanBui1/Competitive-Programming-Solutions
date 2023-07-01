x = int(input())
n = int(input())
coins = [int(input()) for i in range(n)]
import math
def dp(goal, lis):
    dist = [math.inf for i in range(goal+1)]
    dist[0] = 0
    for coin in lis:
        for i in range(goal+1):
            if i - coin >= 0:
                dist[i] = min(dist[i], dist[i-coin]+1)
    print (dist[goal])
dp(x, coins)