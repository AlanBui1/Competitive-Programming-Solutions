import sys
input = sys.stdin.readline

n, m = map(int, input().split())

line = " "+input().strip("\n")

conv = {}

for i in range(n):
    code, bits = map(str, input().split())
    if bits in conv:
        if conv[bits] < code:
            continue 
    conv[bits] = code

def comp(a, b, alen, blen):
    if "INF" in a:
        return False
    if "INF" in b:
        return True
    if alen < blen:
        return True
    if blen < alen:
        return False
    
    if a < b:
        return True
    return False

if n == 1:
    print(m*code)
else:

    inf = "INF"

    dp = [inf for i in range(m+1)]
    lens = [int(1e18) for i in range(m+1)]
    dp[0] = ""
    lens[0] = 0

    for i in range(1, m+1):
        cnt = 0
        for k in range(i, m+2):
            cnt += 1
            if line[i:k] in conv:
                if comp(dp[i-1]+conv[line[i:k]], dp[k-1], len(dp[i-1]+conv[line[i:k]]), lens[k-1]):
                    dp[k-1]= dp[i-1]+conv[line[i:k]]
                    lens[k-1] = len(dp[i-1]+conv[line[i:k]])
            if cnt > 15:
                break

    print(dp[-1])