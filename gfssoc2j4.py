import sys; input = sys.stdin.readline

n, q= map(int, input().split())

lis = [0]+[int(i) for i in input().split()]

for i in range(1, n+1):
    lis[i] += lis[i-1]

for i in range(q):
    a, b = map(int, input().split())
    
    ans = lis[n]

    ans -= lis[b]

    ans += lis[a-1]
        
    print(ans)