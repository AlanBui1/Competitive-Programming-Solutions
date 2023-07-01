import sys; input = sys.stdin.readline
MAXK = 10**5 + 5

n, k = map(int, input().split())
a = [int(i) for i in input().split()]
nax = a[0]

states = [False for i in range(MAXK)]
states[k]= True


for i in range(k-1, -1, -1):
    if nax + i > k:
        states[i] = True
    else:
        for option in a:
            if i+option > k:
                break

            if states[i+option]:
                states[i] = False
                break

            else:
                states[i] = True
                

win = False
for i in a:
    if states[i]:
        win = True
        print("First")
        break

if not win:
    print("Second")