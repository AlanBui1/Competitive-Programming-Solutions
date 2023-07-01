x = int(input())
m = int(input())

works =0
for i in range(1000):
    if (i*x)%m == 1:
        print(i)
        works= 1
        break
    
if not works:
    print("No such integer exists.")