import sys
input = sys.stdin.readline

def solve():
    s, t = map(str, input().split())

    v1 = v2 = 0
    cnt = 0
    for i in s:
        cnt += 1
        if i in "aeiou":
            v1 ^= cnt
    cnt = 0
    for i in t:
        cnt += 1
        if i in "aeiou":
            v2 ^= cnt

    if v1 == v2:
        print("same")
    else:
        print("different")
    
q = 5
for _ in range(q):
    solve()