n = int(input())
way = input()

if n%2 == 0:
    if way == "left":
        print("right")
    else:
        print("left")
        
else:
    print(way)