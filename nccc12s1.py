fib = [0, 1]
while fib[-1] < 100000:
    fib.append(fib[-1] + fib[-2])

T= int(input())
for _ in range(T):
    n = int(input())
    if n not in fib:
        print("NO")
        continue

    if n == 2 or n==3:
        print("NO")
        continue
    
    if n%2 == 0:
        print("YES")
        continue
    f = 3
    flag = 0
    while f*f <= n:
        if n%f == 0:
            flag = 1
            break
        f += 2

    if flag:
        print("YES")
    else:
        print("NO")