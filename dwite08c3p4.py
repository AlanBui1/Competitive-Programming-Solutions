import math
for k in range(5):
    goal = int(input())
    n = int(input())
    coins = [int(input()) for i in range(n)]
    coins.sort()
    dist = [math.inf for i in range(goal+1)]
    for x in range(len(coins)):
        for i in range(1,goal+1,1):
            if i/coins[x] == i//coins[x] and i/coins[x] < dist[i]:
                dist[i] = i/coins[x]
            if i//coins[x] + dist[i%coins[x]] < dist[i]:
                dist[i] = i//coins[x] +dist[i%coins[x]]
    print(int(dist[goal]))