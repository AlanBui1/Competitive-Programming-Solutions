a= int(input())
b= int(input())
r= int(input())

if a > r:
    print("Bob overdoses on day 1.")
else:
    amt = a/2
    amt += b
    if amt > r:
        print("Bob overdoses on day 2.")
    else:
        print("Bob never overdoses.")