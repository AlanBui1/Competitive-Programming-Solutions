import sys
input = sys.stdin.readline
from math import ceil

def solve():
    t = int(input())
    for i in range(t):
        a, b = map(int, input().split())

        k = ceil(a/b*100)

        if k > 100:
            print('sus')
        elif k == 100:
            print("average")
        elif k >= 98:
            print("below average")

        elif k >= 95:
            print("can't eat dinner")

        elif k >= 90:
            print("don't come home")

        else:
            print("find a new home")
solve()