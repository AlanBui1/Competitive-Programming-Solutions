N = int(input())

for i in range (0,N,1):
    x = input()
    s = int(x.index(' '))
    ans = int(x[0:s]) - int(x[s:])
    print(ans)