# import sys
# input = sys.stdin.readline

def solve():
    l = [int(i) for i in input().split()]
    l.sort()
    order = input()
  
    for i in order:
        print(l[ord(i)-ord('A')], end = " ")
    
q = 1
for _ in range(q):
    solve()