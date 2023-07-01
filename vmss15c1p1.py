a = int(input())
ans = int(1e9)
for i in range(1, a+1):
    if a%i == 0:
        ans = min(ans, 2*(i+(a//i)))
        
print(ans)