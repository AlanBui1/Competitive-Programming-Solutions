import sys
input = sys.stdin.readline
def solve():
    perc = 0
    for i in range(3):
        reg = float(input())
        sale = float(input())
        perc = max(perc, (reg-sale)/reg)

    print(str("%.3f"%(perc*100)).rjust(7))

for i in range(5):
    solve()