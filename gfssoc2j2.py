n = int(input())
lhs = 1
rhs = 1

for i in range(n):
    ans = ""
    if lhs % 91 == 0:
        ans += "Fizz Fuzz "
    elif lhs % 7 == 0:
        ans += "Fizz "
    elif lhs % 13 == 0:
        ans += "Fuzz "
    else:
        ans += str(lhs)+" "
        
    if rhs % 91 == 0:
        ans += "Fizz Fuzz"
    elif rhs % 7 == 0:
        ans += "Fizz"
    elif rhs % 13 == 0:
        ans += "Fuzz"
    else:
        ans += str(rhs)
    lhs += 1
    rhs += 2
    print(ans)