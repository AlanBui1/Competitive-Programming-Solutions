c, n = map(int, input().split())

conv = {"Math": 4, "Chemistry":3, "English":2, "TOK":1}
lis = []
ans = 0
for i in range(c):
    x = input()
    lis.append(conv[x])
lis.sort()

if sum(lis) >n:
    print("Go to Metro")
    x = 0
    a = 0
    for i in range(c):
        if lis[i] + x < n:
            x += lis[i]
            a+=1
        else:
            break
    print(a)

else:
    print('YEA BOI')