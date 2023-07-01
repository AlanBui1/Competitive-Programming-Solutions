import sys
input = sys.stdin.readline

def solve():

    line = input()
    cnt =0 
    if "B" not in line:
        cnt += 1
        print("B")
    if "F" not in line:
        cnt += 1
        print("F")
    if "T" not in line:
        cnt += 1
        print("T")
    if "L" not in line:
        cnt += 1
        print("L")
    if "C" not in line:
        cnt += 1
        print("C")

    if cnt == 0:
        print("NO MISSING PARTS")

        
solve()