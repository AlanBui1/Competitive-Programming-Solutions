n = int(input())
def solve():
    a, b = input().split()
    
    if len(a) >= 2:
        if a[-2] == "1" and a[-1] == "7":
            print("NO")
            return
        
    if len(b) >= 2:
        if b[-2] == "1" and b[-1] == "7":
            print("NO")
            return 
        
    if a[-1] == "7":
        if len(b) >= 2:
            if b[-2] == "1" and b[-1] == "1":
                print("YES")
                return
            else:
                print("NO")
                return
        else:
            print("NO")
            return
        
    if b[-1] == "7":
        if len(a) >= 2:
            if a[-2] == "1" and a[-1] == "1":
                print("YES")
                return
            else:
                print("NO")
                return
        else:
            print("NO")
            return
    print("NO")
for i in range(n):
    solve()