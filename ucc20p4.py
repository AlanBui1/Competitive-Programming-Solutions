import sys; input = sys.stdin.readline

n = int(input())

if n == 1:
    x= int(input())
    print(x)

elif n == 2:
    x = int(input())
    y = int(input())

    print(int(x+y - (min(x, y)/4)))

else:
    dp = [0 for i in range(n+5)]
    x = int(input())
    dp[1] = x
    y = int(input())
    dp[2] = x+y - (min(x, y)/4)

    prices = [0,x, y]
    for i in range(3, n+1):
        price = int(input())
        prices.append(price)
        dp[i] = min(prices[i]+dp[i-1], dp[i-2] + prices[i-1]+prices[i] - (min(prices[i], prices[i-1])/4), dp[i-3] + prices[i-2]+prices[i-1]+prices[i] - (min(prices[i], prices[i-1], prices[i-2])/2) )

    print(int(dp[n]))