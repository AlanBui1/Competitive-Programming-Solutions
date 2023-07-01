n = int(input())

c= float(input())

x = 0
for i in range(n):
    x += float(input())

if x <= c:
    print("%.2f" %(c - x))
else:
    print("Fardin's broke")