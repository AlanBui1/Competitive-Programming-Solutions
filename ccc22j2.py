import sys
input = sys.stdin.readline

def solve():
    flag= False
    ans = 0

    n = int(input())
    for i in range(n):
        pts = int(input())
        foul = int(input())
        score = 5*pts
        score -= 3*foul

        if score <= 40:
            flag = True
        else:
            ans += 1

    if not flag:
        print(str(ans)+"+")
    else:
        print(str(ans))
    
q = 1
for _ in range(q):
    solve()