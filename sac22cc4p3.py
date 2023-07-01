import sys
input = sys.stdin.readline
n = int(input())
arr = [int(i) for i in input().split()]
arr.sort()
if n%2 == 1:
    M = arr[n//2]
else:
    M = (arr[n//2]+arr[(n//2)-1])//2

print(M)