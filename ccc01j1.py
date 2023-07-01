h = int(input())
for i in range(1, h+1, 2):
    print("*"*i, end="")
    print(" "*((2*h) - (2*i)), end="")
    print("*"*i)

for i in range(h-2,-1,-2):
    print("*"*i, end="")
    print(" "*((2*h) - (2*i)), end="")
    print("*"*i)