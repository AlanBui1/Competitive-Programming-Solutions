import sys
input = sys.stdin.readline
from math import inf
from pprint import pprint as pp
import copy

n = int(input())
board = [[int(i) for i in input().split()]for k in range(n)]
oldBottom = [[board[n-1][0]]+[-inf, -inf, -inf, -inf]]

for i in range(1, n):
    oldBottom.append([oldBottom[i-1][0]+board[n-1][i]]+[-inf, -inf, -inf, -inf])
    
side = [-inf for i in range(n)]
side[n-1] = oldBottom[0]

for i in range(n-2, -1, -1):
    side[i] = [side[i+1][0]+board[i][0]]+[-inf, -inf, -inf, -inf]

def top5(lis1, lis2):
    lis = lis1+lis2
    lis.sort(reverse=True)
    return lis[0:5]

nextBottom = [side[i]]+[-inf for i in range(n-1)]
for i in range(n-2, -1, -1):
    nextBottom[0] = side[i]
    for k in range(1, n):
        nextBottom[k] = [board[i][k]+ j for j in top5(oldBottom[k], nextBottom[k-1])]

    oldBottom = copy.deepcopy(nextBottom)

for i in range(5):
    print(oldBottom[n-1][i])