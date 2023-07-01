p1 = input()
p2 = input()

n = int(input())
for i in range(n):
    baby = input()
    flag = 0
    for a in baby:
        if a == a.upper():
            if a in p1 or a in p2:
                continue
            else:
                flag = 1
        else:
            if a in p1 and a in p2:
                continue
            else:
                flag = 1

    
        
    if flag:
        print("Not their baby!")
    if not flag:
        print("Possible baby.")