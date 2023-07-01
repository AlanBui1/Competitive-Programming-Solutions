import sys
input = sys.stdin.readline
from random import randint, shuffle


def change():
    for x, y in ans:
        lis = [i for i in a[x-1:y]]
        lis.sort()
        for i in range(x-1, y):
            a[i] = lis[i-x+1]

for _ in range(1):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]

    # n = 10
    # a = [randint(0,1) for i in range(n)]
    # temp = [i for i in a]
    # b = temp
    # shuffle(b)

    A = B = 0
    flag = 0
    for i in range(n-1, -1, -1):
        A += a[i]
        B += b[i]
        if A > B:
            print(-1)
            flag = 1
            break

    if flag:
        break

    if a.count(1) != b.count(1):
        print(-1)
    
    elif b[0] == 1 and a[0] == 0:
        print(-1)
    
    elif b[-1] == 0 and a[-1] == 1:
        print(-1)
    
    else:
        ans = []
        suff = [0 for i in range(n+1)]
        for i in range(n-1, -1, -1):
            suff[i] = suff[i+1] + a[i]
    
        sub = 0
    
        ind = n-1
    
        l = 0
        r = n-1
        
        while ind >= 0:
            cnt = 0
            if b[ind] == 0:
                ind-=1
                continue
    
            while b[ind] == 1:
                ind -= 1
                cnt += 1
                if ind < 0:
                    break
    
            lo = l
            hi = r
    
            largest = -1
    
            while lo <= hi:
                mid = (lo+hi)//2
    
                if suff[mid] - sub == cnt:
                    largest = max(largest, mid)
                    lo = mid+1
    
                elif suff[mid] - sub > cnt:
                    lo = mid+1
    
                else:
                    hi = mid-1
    
            if largest == -1:
                print(-1)
                break
    
            sub += cnt
    
            if largest != ind+1:
                ans.append([largest+1, ind+cnt+1])
            
            r = largest
    
       
        # change()
        # if a != b:
        #     print(-1)
        #     break

        print(len(ans))
        for i in ans:
            print(*i)