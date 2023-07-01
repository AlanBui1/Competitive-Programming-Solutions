n = int(input())
a = [int(i) for i in input().split()]
cnt = [0, 0, 0]
lis = [[], [], []]

for i in a:
    lis[i%3].append(i)
    cnt[i%3] += 1

if cnt[0] > n/2 + 1:
    print("impossible")

else:
    ans = []

    if cnt[1] >= cnt[0]:
        for i in range(cnt[0] - 1):
            ans.append(0)
            ans.append(1)
            cnt[0] -= 1
            cnt[1] -= 1
        for i in range(cnt[1]):
            ans.append(1)
        if cnt[0]:
            ans.append(0)
        for i in range(cnt[2]):
            ans.append(2)

    else:
        if cnt[2] >= cnt[0]:
            for i in range(cnt[0] - 1):
                ans.append(0)
                ans.append(2)
                cnt[0] -= 1
                cnt[2] -= 1
            for i in range(cnt[2]):
                ans.append(2)
            if cnt[0]:
                ans.append(0)
            for i in range(cnt[1]):
                ans.append(1)

        else:
            for i in range(cnt[1]):
                ans.append(0)
                ans.append(1)
                cnt[0] -= 1
            for i in range(min(cnt[2], cnt[0])):
                ans.append(0)
                ans.append(2)
                cnt[2] -= 1
                cnt[0] -= 1
            for i in range(cnt[2]):
                ans.append(2)
            for i in range(cnt[0]):
                ans.append(0)

    A = []
    p = [0, 0, 0]

    for i in ans:
        A.append(lis[i][p[i]])
        p[i] += 1
    for i in range(1, n):
        if (A[i] + A[i-1])%3 == 0:
            A = []
            break
    if A:
        print(*A)
    else:
        print("impossible")