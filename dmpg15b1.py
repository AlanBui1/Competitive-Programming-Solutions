def solve():
    num = input()

    if len(num) != 10:
        print("not a phone number")
        return

    for i in range(10):
        if num[i] not in "1234567890":
            print("not a phone number")
            return

    code = num[:3]
    if code != "416" and code != "647":
        print("not a phone number")
        return

    print("("+code+")-"+num[3:6]+"-"+num[6:])

n = int(input())
for i in range(n):
    solve()