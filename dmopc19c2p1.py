import sys
input = sys.stdin.readline

n = int(input())

lis = [int(i) for i in input().split()]
lis.sort()

MIN = lis[0]
MAX = lis[-1]

q1 = lis[0:n//2]
if n%2 == 0:
    q2 = lis[n//2:]
else:
    q2 = lis[(n//2)+1:]
if len(q1)%2 == 1:
    Q1 = q1[len(q1)//2]
else:
    Q1 = (q1[len(q1)//2]+q1[(len(q1)//2)-1])/2

if len(q2)%2 == 1:
    Q2 = q2[len(q2)//2]
else:
    Q2 = (q2[len(q2)//2]+q2[(len(q2)//2)-1])/2

if len(lis)%2 == 1:
    Q3 = lis[len(lis)//2]
else:
    Q3 = (lis[len(lis)//2]+lis[(len(lis)//2)-1])/2

print(MIN, MAX, Q1, Q3, Q2)