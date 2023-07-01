n = int(input())

arr = []

for i in range(n):
    m, s = map(int, input().split())
    
    arr.append(60*m +s)
    
x, y= map(int, input().split())
ans = 0

tim = x*60 +y
arr.sort()

for i in range(n):
    if tim >= arr[i]:
        ans += 1
        tim -= arr[i]
        
print(ans)