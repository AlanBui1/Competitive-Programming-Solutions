n, y = map(int, input().split())

names = [input() for i in range(n)]
enjoy = [int(i) for i in input().split()]

conv = {}

for i in range(n):
    conv[names[i]] = enjoy[i]
    
ans = 0
for i in range(y):
    movie = input()
    ans += conv[movie]
    conv[movie] = 0
    
print(ans)