for _ in range(5):
    word = input()
    rev = word[::-1]

    dp = [[0 for i in range(len(word)+1)]for k in range(len(word)+1)]
    ans =1
    for i in range(1, len(word)+1):
        for k in range(1, len(word)+1):
            dp[i][k] = max(dp[i-1][k], dp[i][k-1])

            if word[i-1] == rev[k-1]:
                dp[i][k] = dp[i-1][k-1]+1

            ans = max(ans, dp[i][k])

    print(ans)