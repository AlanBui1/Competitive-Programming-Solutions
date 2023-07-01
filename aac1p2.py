n, d, k, x = map(int, input().split())
spds = []

for i in range(n):
    a = int(input())
    spds.append(a)

P = int(input())

def change(origspd):
    val = int(origspd*((100-x)/100))
    return val

spds.sort(reverse=True)
flag = True
for i in range(n):
    while k>0 and spds[i]>=P:
        spds[i] = change(spds[i])
        k-=1

    if spds[i]>=P:
        flag = False
        break

if not flag:
    print("NO")
else:
    print("YES")