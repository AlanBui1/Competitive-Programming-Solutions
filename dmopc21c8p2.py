import sys
input = sys.stdin.readline
MOD = int(1e9) + 7
def fastPow(base, pow):
    mult = base
    ret = 1

    while pow:
        if pow&1:
            ret *= mult
        pow //= 2
        mult *= mult
        mult %= MOD
        ret %= MOD
    return ret

def ways(start, lis, m, n):
    #even cols
    want = 0
    highest = 0
    smallest = int(1e9)
    numZ = 0
    
    for i in range(start, n, 2):
        if lis[0][i] != 0 and lis[1][i] != 0:
            want = lis[0][i] + lis[1][i]
            break
        highest = max(highest, lis[0][i], lis[1][i])
        if lis[0][i] == 0 and lis[1][i] == 0:
            numZ += 1
        if lis[0][i] != 0:
            smallest = min(smallest, lis[0][i])
        if lis[1][i] != 0:
            smallest = min(smallest, lis[1][i])
        
    ways = 1

    if want > 0:    
        for i in range(start, n, 2):
            if lis[0][i] == 0 and lis[1][i] == 0:
                MIN = max(want - m, 1)
                MAX = want - MIN
                ways *= MAX - MIN + 1
                # print("ALDJSKLA", MAX - MIN + 1)
                
            elif lis[0][i] != 0 and lis[1][i] != 0:
                if lis[0][i] + lis[1][i] != want:
                    # print("ASDJKALJ")
                    return 0
                
            elif lis[0][i] != 0:
                lis[1][i] = want - lis[0][i]
                if lis[0][i] < 1 or lis[1][i] < 1 or lis[0][i] >m or lis[1][i] > m:
                   
                    return 0
            else:
                lis[0][i] = want - lis[1][i]
                if lis[0][i] < 1 or lis[1][i] < 1 or lis[0][i] >m or lis[1][i] > m:
                   
                    return 0
            ways %= MOD

    elif highest == 0: 
        ways = 0
        for i in range(2, 2*m+1):
            MIN = max(i - m, 1)
            MAX = i - MIN
            # print(m, i, fastPow(MAX - MIN + 1, numZ))
            ways += fastPow(MAX - MIN + 1, numZ)
            ways %= MOD
    else:
        ways = 0
        # print(numZ)
        for i in range(highest+1,smallest+m+1):
            MIN = max(i - m, 1)
            MAX = i - MIN
            # print(m, i, fastPow(2*m -i+1, numZ))
            ways += fastPow(MAX - MIN + 1, numZ)
            ways %= MOD
    
    return ways

def bruteForce(n, m, lis):
    bf = [-1, -1, 1, 2, 1]
    tot = 0
    for i in range(2, 5):
        want = i
        ways = 1

        for k in range(0, n, 2):
            if lis[0][k] == 0 and lis[1][k] == 0:
                ways *= bf[want]
            elif lis[0][k] != 0 and lis[1][k] != 0:
                if lis[0][k] + lis[1][k] != want:
                    ways = 0
                    break
            elif lis[0][k] != 0:
                ele = want - lis[0][k]
                if ele < 1 or ele > m:
                    ways = 0
                    break
      
            else:
                ele = want - lis[1][k]
                if ele < 1 or ele > m:
                    ways = 0
                    break

        tot += ways
    tot2 = 0
    for i in range(2, 5):
        want = i
        ways = 1

        for k in range(1, n, 2):
            if lis[0][k] == 0 and lis[1][k] == 0:
                ways *= bf[want]
            elif lis[0][k] != 0 and lis[1][k] != 0:
                if lis[0][k] + lis[1][k] != want:
                    ways = 0
                    break
            elif lis[0][k] != 0:
                ele = want - lis[0][k]
                if m < ele or ele < 1:
                    ways = 0
                    break
      
            else:
                ele = want - lis[1][k]
                if m < ele or ele < 1:
                    ways = 0
                    break
        # print(i, ways)
        tot2 += ways
    # print(tot, tot2)
    return tot*tot2%MOD

import random
def solve():
    n, m = map(int, input().split())
    # n = 5
    # m = 2
    # lis = [[random.randint(0, 2) for i in range(n)] for k in range(2)]
    lis = [[int(i) for i in input().split()] for k in range(2)]
    # print(lis)
    for innerList in lis:
        for ele in innerList:
            if ele > m:
                print(0)
                return
    # print(ways(0, lis, m, n))    
    # print(ways(1, lis, m, n))    
    # print(bruteForce(n, m, lis))
    # a1 = bruteForce(n, m, lis)
    a2 = ways(0, lis, m, n) * ways(1, lis, m, n)%MOD
    print(a2)
    # if a1 != a2:
        # print(lis)
        # print(bruteForce(n, m, lis))
        # print(ways(0, lis, m, n))
        # print(ways(1, lis, m, n)%MOD)
        # return
    # ways(0, lis, m, n)
for i in range(1):
    solve()
'''
5 2
0 1 2 1 0
0 0 1 0 2
'''