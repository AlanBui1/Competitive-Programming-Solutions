n = int(input())
c = [len(input()) for i in range(n)]
m = int(input())
cnt = [int(0) for i in range(m)]

for i in range(n):
    print(cnt.index(min(cnt))+1)
    cnt[cnt.index(min(cnt))] +=  c[i]