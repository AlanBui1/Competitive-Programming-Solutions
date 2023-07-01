import sys; input = sys.stdin.readline
n = int(input())
ppl = [int(i) for i in input().split()]

m = int(1e18)
ind = -1
for i in range(n):
    if ppl[i] < m:
        m = ppl[i]
        ind = i

lis = [ppl[(i+ind)%n] for i in range(n)]
ops = []
moves = 0

def works(x):
    lis[0] -= x
    lis[-1] -= x
    toSubtract = lis[0]
    for i in range(n-1):
        if lis[i+1] - toSubtract < 0:
            lis[0] += x
            lis[-1] += x
            return False

        toSubtract = lis[i+1] - toSubtract
    
    if toSubtract == 0:
        lis[0] += x
        lis[-1] += x
        return True

    lis[0] += x
    lis[-1] += x
    return False

flag = False
for i in range(lis[0], -1, -1):
    if works(i):
        flag = True
        ops.append([n-1, i])
        moves = i
        lis[0] -= i
        lis[-1] -= i
    
        for k in range(n-1):
            lis[k+1] -= lis[k]
            moves += lis[k]
            ops.append([k, lis[k]])

        break

if not flag:
    print("NO")
else:
    print("YES")
    print(moves)
    for i in range(len(ops)):
        for k in range(ops[i][1]):
            print((ops[i][0]+ind)%n, (ops[i][0]+1+ind)%n)