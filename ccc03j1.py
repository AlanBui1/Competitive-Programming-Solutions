t=  int(input())
s = int(input())
h= int(input())

for i in range(t):
    ans = ""
    for k in range(2):
        ans += "*"
        ans += " "*s
    ans += "*"
    print(ans)

print("*"*(3 + (s*2)))

for i in range(h):
    print(" "*(s+1), end="")
    print("*")