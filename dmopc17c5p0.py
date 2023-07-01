b = int(input())
p = int(input())
v = input()

if v == "Y":
    if b/p >= 5:
        print("B")
    elif b/p >= 2:
        print("D")
    else:
        print("NO PIZZA")
else:
    if b/p >= 5:
        print("A")
    elif b/p >= 2:
        print("C")
    else:
        print("NO PIZZA")