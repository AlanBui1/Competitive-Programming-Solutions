def solve():
    n = int(input())
    a = [int(I) for I in input().split()]
    C = a.count(0)
    if C == n:
        print("YES")
    
    elif C == 0:
        for i in range(n-1):
            if a[i] > a[i+1]:
                print("NO")
                return
        print("YES")
    else:
        lis = [0 for i in range(n)]
        if n <= 100:
            for i in range(n):
                if a[i] != 0:
                    for k in range(n):
                        if a[k] == 0:
                            lis[k] = a[i]
                        else:
                            lis[k] = a[k]
                    flag = 1
                    for k in range(n-1):
                        if lis[k] > lis[k+1]:
                            flag = 0
                            break

                    if flag:
                        print("YES")
                        return
            print("NO")
        else:
            
            for i in range(n-2, -1, -1):
                if a[i] == 0 and a[i+1] != 0:
                    v = a[i+1]
    
                    for k in range(n):
                        if a[k] == 0:
                            a[k] = v
    
                    break
                    
            for i in range(n-1):
                if a[i] > a[i+1]:
                    print("NO")
                    return
            print("YES")
solve()