import sys
input = sys.stdin.readline

def gcd(a, b):
    if b== 0:
        return a

    return gcd(b, a%b)

n, q = map(int, input().split())
A = [-1 for i in range(n)]
B = [1 for i in range(n)]
C = [-1 for i in range(n)]
side = [0 for i in range(n)]
trees = []

for i in range(n):
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    trees.append([x1, y1, x2, y2, x3, y3])
    A[i] *= y3-y2
    B[i] = x3-x2

    G = gcd(A[i], B[i])
    A[i] //= G
    B[i] //= G

    '''
    Ax + By + C = 0
    Ax + By = -C
    '''
    
    C[i] = -((A[i]*x2) + (B[i]*y2))

    '''
    Ax + By + C < 0
    left side (-1)

    Ax + By + C > 0
    right side (1)
    '''

    if (A[i]*x1) + (B[i]*y1) + C[i] < 0:
        side[i] = -1

    else:
        side[i] = 1


def inTree(x, y, T, ind):
    x1 = min(T[0], T[4])
    y1 = min(T[1], T[3])
    x2 = max(T[4], T[0])
    y2 = max(T[3], T[1])


    if x1 <= x <= x2 and y1 <= y <= y2:
        S = 1
        if (A[ind]*x) + (B[ind]*y) + C[ind] < 0:
            S = -1

        if (A[ind]*x) + (B[ind]*y) + C[ind] == 0:
            return 1
        
        if side[ind] == S:
            return 1

    
    return 0

for _ in range(q):
    x, y = map(int, input().split())
    cnt = 0
    for i in range(n):
        if inTree(x, y, trees[i], i):
            cnt += 1  

    print(cnt)