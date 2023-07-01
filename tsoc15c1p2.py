import sys
input = sys.stdin.readline


r, c = map(int, input().split())
w, l = map(int, input().split())
want = w*l

arr = [[0 for i in range(1010)]for k in range(1010)]

n = int(input())
found = 0
ans = 0
for i in range(n):
    x, y = map(int, input().split())
    if found:
        continue

    for j in range(max(1, x-w+1), x+1):
        if found:
            break
        for k in range(max(1, y-l+1), y+1):
            arr[j][k] += 1
            if arr[j][k] == want:
                found = 1
                ans = i+1
                break

if found:
    print("Special store was found on:", ans)
else:
    print("Special store was not located")