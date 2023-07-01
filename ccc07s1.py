n = int(input())

for i in range(n):
    age = [int(k) for k in input().split()]
    if age[0] < 1989:
        print('Yes')
    elif age[0] > 1989:
        print('No')
    elif age[1] > 2:
        print('No')
    elif age[1] == 1:
        print('Yes')
    elif age[1] == 2:
        if age[2] > 27:
            print('No')
        else:
            print('Yes')