N = int(input())
x1 = 0
ren = int(input())
for i in range (1, N - 1, 1):
    x = int(input())
    if x > x1:
        x1 = x

if x1 >= ren:
     print("NO")
else:
    print("YES")