import sys; input = sys.stdin.readline

n, k = map(int, input().split())

lis = [int(i) for i in input().split()]

lis.sort(reverse = True)
ans = 0
for i in range(k):
    ans += lis[i]
    
print(ans)