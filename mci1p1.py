a, b = map(int, input().split())

for i in range(1, b+1):
    if b%i == 0:
        c = i
        d = b//i
        if c + d == a:
            
            print(c, d)
            break