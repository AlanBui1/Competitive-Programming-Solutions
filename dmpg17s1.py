import sys
input = sys.stdin.readline

n = int(input())

arr = [int(i) for i in input().split()]

arr.sort()

d = int(1e10)

for i in range(n-1):
    d = min(d, abs(arr[i]-arr[i+1]))
    
print(d)