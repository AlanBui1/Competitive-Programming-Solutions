import sys
input = sys.stdin.readline

n = int(input())
c = int(input())
lis = [int(i) for i in input().split()]

for i in range(n):
    lis[i] += c*2
    
print(*lis)