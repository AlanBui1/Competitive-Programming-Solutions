n, k = map(int, input().split())
possible = [0 for i in range(360)]

lis = [int(i) for i in input().split()]
possible[0]= 1
for angle in lis:
    for i in range(360):
        if possible[i]:
            possible[(i+360+angle)%360] = 1
            possible[(360+angle-i)%360] = 1

    for _ in range(361):
        possible[(angle*_)%360] = 1

angles = [int(i) for i in input().split()]
for a in angles:

    if possible[a%360]:
        print("YES")
    else:
        print("NO")