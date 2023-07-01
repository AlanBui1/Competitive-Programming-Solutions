x = int(input())
x *= 2

'''
x = (L+R)/2*(R-L+1)
2x = (L+R)*(R-L+1)

R-L+1 = a
R+L = b

2L-1 = b-a
2L = b-a+1
L = (b-a+1)/2

'''

lis = []
for i in range(2, int(x**0.5)+1):
    if x%i == 0:
        lis.append([i, x//i])

for a, b in lis:
    if (b-a+1)%2 == 1:
        continue
    L = (b-a+1)//2
    R = b-L

    print(L, R)