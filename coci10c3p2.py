import sys
input = sys.stdin.readline

def solve():
    a, b= map(str, input().split())
    highest = int(a.replace("5", "6")) + int(b.replace("5", "6"))

    lowest = int(a.replace("6", "5")) + int(b.replace("6", "5"))

    print(lowest, highest)
    
    
q = 1
for _ in range(q):
    solve()