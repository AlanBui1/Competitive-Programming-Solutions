n = int(input())
x = [int(i) for i in input().split()]
f = [int(i) for i in input().split()]

a = 0
b = 0
for i in range(n):
    if x[i] > f[i]:
        a += 1
    elif x[i] < f[i]:
        b+=1
print(a, b)
if a > b:
    print("Xyene")
elif a == b:
    print("Tie")
else:
    print("FatalEagle")