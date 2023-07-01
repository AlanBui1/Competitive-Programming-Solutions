s1 = input().lower()
s2 = input().lower()

lis1 = [ord(i)-96 for i in s1]
lis2 = [ord(i)-96 for i in s2]

c1 = 0
c2 = 0

def fastPower(base, p, mult):
    while p > 0:
        if p&1:
            base *= mult
        p//=2
        mult *= mult
        mult %= 10
        base %= 10
    return base

for i in range(len(s1)):
    c1 += fastPower(lis1[i], i, lis1[i])
    c1 %= 10

for i in range(len(s2)):
    c2 += fastPower(lis2[i], i, lis2[i])
    c2 %= 10

if c1 == 0:
    c1 = 10
if c2 == 0:
    c2 = 10
print(c1+c2)