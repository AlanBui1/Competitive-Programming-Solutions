import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)

c, s, p = map(int, input().split())

n = int(input())
lis = [[int(i) for i in input().split()] for k in range(n)]

def recur(numPpl, curPerson, curC, curS, curP):
    global n, c, s, p
    if numPpl == 5 or curPerson == n:
        return min(100, 100*min(curC/c, curS/s, curP/p))

    return max(recur(numPpl, curPerson+1, curC, curS, curP), 
               recur(numPpl+1, curPerson+1, curC+lis[curPerson][0], curS+lis[curPerson][1], curP+lis[curPerson][2]))

if n <= 5:
    C = 0
    S = 0
    P = 0
    for i in range(n):
        C += lis[i][0]
        S += lis[i][1]
        P += lis[i][2]

    print("%.1f" %(min(100, 100*min(C/c, S/s, P/p))))

else:
    ans = recur(0, 0, 0, 0, 0)
    print("%.1f" %(ans))