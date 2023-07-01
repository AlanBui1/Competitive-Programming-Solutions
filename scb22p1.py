def solve():

    line = "1234567890"
    num = input()
    
    for i in range(5):
        cur = num[i]
        nxt = num[i+1]
        
        if abs(line.index(cur) - line.index(nxt)) == 1:
            continue
        
        print("INVALID")
        return
    
    print("VALID")
    
solve()