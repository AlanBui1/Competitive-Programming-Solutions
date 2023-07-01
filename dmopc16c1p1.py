n = int(input())
arr = [int(i) for i in input().split()]
ans =0

for i in range(n):
    if i%2 == arr[i]%2:
        ans +=1
print(ans)