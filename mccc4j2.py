n, a, b = map(int, input().split())

a1 = 0
a2 = 0

for i in range(n):
    x, y = map(int, input().split())
    if x < a:
        a1 += 1
    else:
        a1 += 2
        
    if y < b:
        a2 += 1
        
    else:
        a2 += 2
        
if a1 < a2:
    print("Andrew wins!")
elif a1 == a2:
    print("Tie!")
else:
    print("Tommy wins!")