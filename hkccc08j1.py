z1 = 0
z3 = 0
C = int(input())
for i in range (0,C,1):
    x = input()
    s=int(x.index(' '))
    z = int(x[0:s]) * int(x[s+1:])
    if z > z1:
        z1 = z
N = int(input())
for i in range (0,N,1):
    x1 = input()
    s1=int(x1.index(' '))
    z2 = int(x1[0:s1]) * int(x1[s1+1:])
    if z2 > z3:
        z3 = z2
if z1>z3:
    print("Casper")
if z3 >z1:
    print("Natalie")
if z3 == z1:
    print("Tie")