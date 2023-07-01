def f(a, b, c, d):
    return (a*1000000)+(b*10000)+(c*100)+d
def m(a, b, c, d):
    return (a*11)+(b*101)+(c*1009)+(d*10007)


for _ in range(5):
    n = int(input())
    flag = False
    ans = []

    for i in range(65, 91):
        if flag:
            break
        for k in range(65, 91):
            if flag:
                break
            for j in range(65, 91):
                if flag:
                    break
                for l in range(65, 91):
                    if f(i,k,j,l)%m(i,k,j,l) == n:
                        flag = True
                        ans = [i,k,j,l]
                        break

    print(*[chr(i) for i in ans], sep = "")