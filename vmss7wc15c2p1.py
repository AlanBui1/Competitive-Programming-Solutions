n = int(input())

prev = -1
cur = int(input())
ans = 0

while n > 1:
    n -= 1

    next = int(input())

    if prev <= 41 and cur <= 41 and next <= 41:
        ans += 1

    prev = cur
    cur = next

if cur <= 41 and prev <= 41:
    ans += 1
print(ans)