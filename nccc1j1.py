n = int(input())
x = n
while True:
    x += 1
    if str(x).count("0") == 0:
        print(x)
        break