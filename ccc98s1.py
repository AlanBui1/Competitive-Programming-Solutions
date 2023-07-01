n = int(input())
for i in range(n):
    line = input().split()
    for i in range(len(line)):
        if len(line[i]) == 4:
            line[i] = "****"

    print(*line)