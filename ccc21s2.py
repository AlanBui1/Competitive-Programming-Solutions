import sys
input = sys.stdin.readline
m = int(input())
n = int(input())
k = int(input())
rows = {}
cols = {}

c = 0
r  =0
tot=0

for i in range(k):
    ind, num = map(str, input().split())
    num = int(num)

    num -= 1
    if ind == "R":
        if num not in rows:
            tot += n
            tot -= 2*(c)
            r+=1
            rows[num] = True

        else:
            tot -= n
            tot += 2*c
            r -= 1
            del rows[num]
            
    if ind == "C":
        if num not in cols:
            tot += m
            tot -= 2*r
            c+=1
            cols[num] = True

        else:
            tot -= m
            tot += 2*r
            c -= 1
            del cols[num]

print(tot)