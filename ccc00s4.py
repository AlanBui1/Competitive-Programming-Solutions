def dp(coins, amount):
    global minCoins
    minCoins = [float('inf')]*(amount+1)

    minCoins[0] = 0;

    for coin in coins:
        for i in range(amount+1):
            if i - coin >= 0:
                minCoins[i] = min(minCoins[i], minCoins[i - coin]+1)
    return minCoins[amount]
import math

goal = int(input())
n = int(input())

coins = [int(input()) for i in range(n)]
coins.sort()
dp(coins, goal)

if minCoins[goal] != math.inf:
    print('Roberta wins in', int(minCoins[goal]), 'strokes.')  
else:
    print('Roberta acknowledges defeat.')