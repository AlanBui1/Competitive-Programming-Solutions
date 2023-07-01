n = int(input())

if n == 1:
    print(1)
if n == 2:
    print(1)
    print(1, 1)
    
if n > 2:
    print(1)
    print(1, 1)
    print(1, 2, 1)
    if n > 3:
        prev = [1, 2, 1]
        for i in range(3, n):
            nxt = [1]
            for k in range(1, i):
                nxt.append(prev[k-1]+prev[k])
            nxt.append(1)
            
            print(*nxt)    
            prev = nxt.copy()