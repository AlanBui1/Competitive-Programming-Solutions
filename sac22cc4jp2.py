def solve():
    n, q = map(int, input().split())
    
    lis = [0 for i in range(n)]
    
    conv = {"square": 1, "triangle": 2, "circle":3}
    
    for i in range(q):
        op, shape, num = map(str, input().split())
        num = int(num)-1
        
        if op == "get":
            if lis[num] == conv[shape]:
                print(1)
            else:
                print(0)
        elif op == "set":
            lis[num] = conv[shape]
    
solve()