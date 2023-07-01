p = int(input())
n = int(input())
r = int(input())
z = 0
num = 0
c = 0
while True:
    if r != 1:
        num += n*(r**z)
        if num > p:
            print(c)
            break
        z += 1
        c += 1
        continue
    z = int(p/n)
    print(z)
    break