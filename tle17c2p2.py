import sys
input = sys.stdin.readline
k = int(input())
floors = [0 for i in range(10**6 + 1)]
unlucky = [int(i) for i in input().split()]
for i in unlucky:
    floors[i] = -1
    
for i in range(1, 10**6 + 1):
    floors[i] += floors[i-1] + 1
    
n = int(input())
for i in range(n):
    floor = int(input())
    print(floors[floor])