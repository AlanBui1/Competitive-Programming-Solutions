import sys
input = sys.stdin.readline

def solve():
    v = int(input())

    '''
    y = vt +(1/2)gt^2
    
    0 = vt +(1/2)gt^2
    0 = 2vt + gt^2
    0 = t(2v + gt)
    => t = 0 or 2v + gt = 0
    gt = -2v
    t = -2v/g
    
    '''
    print((-2)*v/(-9.8))
    
    
    
q = 1
for _ in range(q):
    solve()