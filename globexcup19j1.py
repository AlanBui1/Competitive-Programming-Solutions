import sys; input = sys.stdin.readline

n, m, a, b, c = map(int, input().split())
win = [int(i) for i in input().split()]

opponents = [int(i) for i in input().split()]

for i in range(c):
    if win[opponents[i]-1]:
        m += a
    else:
        m  -= b
        
print(m)