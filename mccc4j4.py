import sys; input = sys.stdin.readline

n, s=  map(int, input().split())
lis = [[int(i) for i in input().split()] for k in range(n//s)]

score = {i:0 for i in range(1, n+1)}

for i in range((s-1)*n//2):
    a, b, c = input().split()
    a = int(a); b= int(b);
    if c == 'W':
        score[a] += 3
    elif c == 'T':
        score[a] += 1
        score[b] += 1
    else:
        score[b]+=3

k = int(input())
ans = ""

newlis = [[[score[i], -i] for i in lis[j]] for j in range(n//s)]

for i in range(n//s):
    newlis[i].sort(reverse = True)
    cur = k-1
    ind = k-1
    ans+= str(abs(newlis[i][ind][1]))
    if i < n//s-1:
        ans += " "
print(ans)