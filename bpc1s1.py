import sys
input = sys.stdin.readline

n = int(input())
lis = [int(i) for i in input().split()]

if n == 2:
    ans = []
    for i in range(4):
        if lis.count(lis[i]) == 2:
            continue
        ans.append(lis[i]//2)
    ans.sort()
    print(*ans)

elif n == 3:
    n2 = n*n
    lis.sort()

    ans = [lis[0]//2]
    ans.append(lis[1]-ans[0])
    ans.append(max(lis)//2)

    ans.sort()
    print(*ans)

else:
    lis.sort()
    ans = [lis[0]//2]
    lis.remove(ans[0]*2)
    ans.append(lis[1]-ans[0])
    lis.remove(ans[-1]*2)
    for i in range(2):
        lis.remove(ans[0]+ans[1])

    while len(ans) < n:
        ans.append(lis[0]-ans[0])
        for i in range(len(ans)-1):
            for k in range(2):
                lis.remove(ans[i]+ans[-1])
        lis.remove(ans[-1]*2)
        
    ans.sort()
    print(*ans)
'''
4
2 4 6 8 3 3 4 4 5 5 5 5 6 6 7 7
'''