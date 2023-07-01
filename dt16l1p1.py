def solve():
    a = int(input())
    op = input()
    b = int(input())

    if op == "$":
        val = (a+b)*(a-b)

    elif op == "@":
        val = (a*b)/((2*a)-3)

    else:
        val = (a*b)*(b-14)

    print("The equation", a, op, b, "is equal to", str(int(val))+".")
solve()