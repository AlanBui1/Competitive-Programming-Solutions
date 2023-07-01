import sys
input = sys.stdin.readline

def solve():

    lis = [int(i) for i in input().split()]
    if lis == [1,2,3,4,5,6,7,8]:
        print("ascending")
    elif lis == [8,7,6,5,4,3,2,1]:
        print("descending")
    else:
        print("mixed")

solve()