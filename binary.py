n = int(input())
lis = []
for i in range(n):
    num = int(input())
    ans = bin(num)
    ans = ans[2: ]
    # print(ans)
    if len(ans) % 4 != 0:
        ans = "0"*(4-(len(ans)%4))+ans

    for i in range(4, len(ans)+5, 5):
        ans = ans[0: i] + " " +ans[i: ]

    print(ans)
    lis.append(ans)