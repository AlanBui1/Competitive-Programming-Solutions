c1 = [int(k) for k in input().split()]
c2 = [int(k) for k in input().split()]
c3 = [int(k) for k in input().split()]
c4 = [int(k) for k in input().split()]
c5 = [int(k) for k in input().split()]

lis = [sum(c1),sum(c2),sum(c3),sum(c4),sum(c5)]
x = (max(sum(c1),sum(c2),sum(c3),sum(c4),sum(c5)))

print(lis.index(x)+1,x)