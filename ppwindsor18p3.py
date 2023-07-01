line1 = "qwertyuiop"
line2 = "asdfghjkl"
line3 = "zxcvbnm"

def pos(x, y):
    for i in x:
        if i not in y:
            return 0
    
    return 1
n= int(input())
ans = 0
for i in range(n):
    line = input()

    if pos(line, line1) or pos(line, line2) or pos(line, line3):
        ans += 1

print(ans)