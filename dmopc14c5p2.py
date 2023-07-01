n = int(input())
highest = -1
for i in range(n):
    a, b = map(int, input().split())
    highest = max(highest, abs(a-b))
print(highest)