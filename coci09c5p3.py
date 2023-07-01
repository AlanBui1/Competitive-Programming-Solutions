import sys
input = sys.stdin.readline

def solve():
    w, l, n = map(int, input().split())
    s = set()
    ans = 0
    for i in range(n):
        top = [int(k) for k in input().split()]
        bot = [int(k) for k in input().split()]
        tup = tuple([w-bot[k]-top[k] for k in range(l)])
        rev = tuple([w-bot[k]-top[k] for k in range(l-1, -1, -1)])

        if tup in s or rev in s:
            s.add(tup)
            s.add(rev)
            continue

        ans += 1
        
        s.add(tup)
        s.add(rev)
    print(ans)
        

solve()