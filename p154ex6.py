p, a, y, b = map(float, input().split())
y=int(y)
while a < b:
    y+=1
    a*= 1 +(p/100)
    
print(y)