# import sys
# input = sys.stdin.readline

def solve():
    line = input()

    cnt = {}

    for i in line:
        if i not in cnt:
            cnt[i] = 0

        cnt[i] += 1

    for i in line:
        if cnt[i] == 1:
            print(i)
            return 

    
q = 5
for _ in range(q):
    solve()