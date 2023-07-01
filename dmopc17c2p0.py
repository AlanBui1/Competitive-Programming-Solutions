x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())
d = int(input())

if ((x2-x3)*(x2-x3)) + ((y2-y3)*(y2-y3))  <= d*d or ((x1-x3)*(x1-x3)) + ((y1-y3)*(y1-y3)) <= d*d:
    print("Yes")
    
else:
    print("No")