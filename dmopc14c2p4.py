import sys
input = sys.stdin.readline
n = int(input())
arr = [int(input()) for i in range(n)]
q = int(input())
x = 0
prefix = []
for i in arr:
  x += i
  prefix.append(x)

for i in range(q):
  a, b = map(int, input().split())
  print(prefix[b] - prefix[a-1] if a > 0 else prefix[b])