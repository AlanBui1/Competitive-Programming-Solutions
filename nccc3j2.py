line = input()
possible = False
def palin(x):
    r = ""
    for i in range(len(x)-1, -1, -1):
        r += x[i]
    return x == r
for i in range(1, len(line)):
    if palin(line[:i]) and palin(line[i:]):
        possible = True

if possible:
    print("YES")
else:
    print("NO")