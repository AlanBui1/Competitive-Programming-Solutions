import sys
input= sys.stdin.readline

n = int(input())
want = [int(i) for i in input().split()]
orig = [i for i in want]
want.sort()

done = 0
lis = []

piles = [[], [i for i in orig]]

lis.append(n)
cur = n-1

for i in range(7*n):
    if done:
        break

    lookingFor = want[cur]
    for k in range(len(piles[1])):
        if lookingFor == piles[1][k]:
            piles[1].remove(lookingFor)
            lis.append(-(k+1))
            if k != 0:
                lis.append(k)
            break

    cur -= 1
    if cur < 0:
        done = 1


print(len(lis))
for i in lis:
    print(i)