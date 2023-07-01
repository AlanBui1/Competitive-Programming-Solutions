n, m= map(int, input().split())
MOD = int(1e9)+7

def fastPow(base, power):
    mult = base
    res = 1
    while power:
        if power&1:
            res *= mult
            res %= MOD
        mult *= mult
        mult %= MOD
        power //= 2
    return res
    

BLUE = 0
RED = 1
YELLOW = 2

dp = [[-1 for i in range(m+1)] for k in range(3)]
dp[BLUE][1] = 1
dp[RED][1] = 1
dp[YELLOW][1] = 1

for i in range(2, m+1):
    dp[BLUE][i] = (dp[RED][i-1] + dp[YELLOW][i-1])%MOD
    dp[YELLOW][i] = (dp[RED][i-1] + dp[YELLOW][i-1] + dp[BLUE][i-1])%MOD
    dp[RED][i] = (dp[RED][i-1] + dp[YELLOW][i-1])%MOD

print(fastPow((dp[RED][-1] + dp[BLUE][-1] + dp[YELLOW][-1])%MOD, n))