t = int(input())

for _ in range(t):
    n = int(input())
    
    square = [[0 for k in range(n)] for i in range(n)]
    for i in range(n):
        for k in range(n):
            square[i][k] = int(input())
    if _ != t-1:
        input()
            
    want = sum(square[0])
    bad = False
    
    for i in range(n):
        if want != sum(square[i]):
            print("no")
            bad = True
            break
        
    if bad:
        continue
    
    for i in range(n):
        s = 0
        for k in range(n):
            s += square[k][i]
        if s != want:
            bad = True
            break
        
    if bad:
        continue
    print("yes")