# import sys
# input = sys.stdin.readline

def solve():
    s = [i for i in input()]

    A = ord('a')
    M = ord('m')
    N = ord('n')
    Z = ord('z')

    lis = [ord(i) for i in s]

    leng = len(lis)
    ind = leng-1

    for i in range(ind, -1, -1):
        if A <= lis[i] <= M:
            lis[i] = A
            break
        else:
            lis[i] = A
            if i == 0:
                lis = [A]+lis
                break

            if lis[i-1] < Z:
                lis[i-1]+= 1
                break
                
    s = [chr(i) for i in lis]
    print(*s, sep = "")

q = 1
for i in range(q):
    solve()