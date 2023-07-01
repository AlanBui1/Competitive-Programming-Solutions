import sys
input = sys.stdin.readline

n, p = map(int, input().split())
lis = []
fuel = 0
for i in range(1, n+1):
    a, b = map(int, input().split())

    if i == p:
        fuel += a
        continue

    if a >= b:
        lis.append([b, a])

lis.sort()
cnt = 1

for x, y in lis:
    if x > fuel:
        continue

    cnt += 1
    fuel -= x
    fuel += y

print(fuel)
print(cnt)