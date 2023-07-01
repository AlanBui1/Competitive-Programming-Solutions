lis = []
x = 1
while True:
    if x**6 <= 1e8:
        lis.append(x**6)
    else:
        break
    x+=1
    
a = int(input())
b = int(input())
ans = 0
for i in lis:
    if a <= i <= b:
        ans+=1

print(ans)