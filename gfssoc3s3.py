n = int(input())

if n == 1:
    print(9)
elif n == 2:
    print(18)
elif n == 17:
    print(99999998)
elif n > 17:
     print(999999998)
else:
    ans = "1"
    digits = 3 + ((n-3)//2)
    if n %2 == 0:
        ans += "9"
    else:
        ans += "0"
    for i in range(digits - 3):
        ans += "9"

    ans += "8"
    print(int(ans)%1000000000)