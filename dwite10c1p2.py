def solve():
    line = input()
    ind = -1
    for i in range(5):
        if line[i] == "*":
            ind = i
            
    for i in range(5):
        x = input()
        if x == "L":
            ind = max(0, ind-1)
        else:
            ind = min(4, ind+1)
            
    ans = ["." for i in range(5)]
    ans[ind] = "*"
    print(*ans, sep="")
    
for i in range(5):
    solve()