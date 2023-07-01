def solve():    
    n, c, v = map(int, input().split())
    
    vowels = "aeiouy"
    line = input()
    
    cons, vows = 0, 0
    
    for i in range(n):
        if line[i] == "y":
            vows += 1
            cons += 1
        elif line[i] in vowels:
            vows += 1
            cons = 0
        else:
            vows = 0
            cons += 1
        if vows > v or cons > c:
            print("NO")
            return
    print("YES")
solve()