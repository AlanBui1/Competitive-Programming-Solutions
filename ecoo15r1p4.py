import sys; input = sys.stdin.readline

words = ["ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"]
lens = [3, 6, 3, 4, 2, 4, 8, 5, 5, 4]

for _ in range(10):
    word = input()
    word = " "+word
    dp = [0 for i in range(len(word)+1)]

    dp[0] = 1

    for i in range(len(word)):
        for k in range(10):
            if i >= lens[k]:
                if word[i-lens[k]+1: i+1] == words[k]:
                    dp[i] += dp[i-lens[k]]

    print(dp[len(word)-2])