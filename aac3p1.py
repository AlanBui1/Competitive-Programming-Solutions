a, b, c, d = map(int, input().split())

if a >= b and c >= d:
    print("Stay home")
elif a <b and c < d:
    print("Go to the department store")
elif a < b:
    print("Go to the grocery store")
else:
    print("Go to the pharmacy")