want = int(input())
ans = []

x = 0
y = 0
z = 0

def word(a, b, c):
    ret = ""
    if a != 0:
        ret += chr(a+96)
    if b != 0:
        ret += chr(b+96)
    ret += chr(c+96)
    return ret

for i in range(want):
    z += 1
    
    if z > 26:
        z %= 26
        y += 1

    if y > 26:
        y %= 26
        x += 1

    ans.append(word(x, y, z))

print(*ans)