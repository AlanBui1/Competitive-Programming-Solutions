n = int(input())
lis = input().split()
lis2 = input().split()

x = 0
y = 0

for i in range(n):
    a = lis[i]
    b = lis2[i]
    if a == "rock":
        if b == "paper":
            y += 1
        elif b == "scissors":
            x += 1
        
    elif a == "paper":
        if b == "rock":
            x += 1
        elif b == "scissors":
            y += 1
    
    else:
        if b == "rock":
            y += 1
        elif b == "paper":
            x += 1
print(x, y)