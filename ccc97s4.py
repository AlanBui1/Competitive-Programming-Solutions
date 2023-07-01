def solve():
    d = dict()
    cnt = 0
    while True:
        line = input()
        if line == "":
            print()
            return
        
        line = line.split()
        for i in range(len(line)):
            if line[i] in d:
                line[i] = d[line[i]]
            else:
                cnt += 1
                d[line[i]] = cnt
        print(*line)
    
t = int(input())
for i in range(t):
    solve()