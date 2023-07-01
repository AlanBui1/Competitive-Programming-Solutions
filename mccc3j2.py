n, k = map(int, input().split())
road = input()
walk = 0
for i in range(n):

    if road[i] == "U":
        k = max(0, k-1)

    elif road[i] == "D":
        k+=1

    if k == 0:
        walk += 1

print(walk)