K = int(input())
K *= 2

def f(x):
    return x*(x+1)

if K == 0:
    print(1)
    print(1)
elif K > f(int(1e6)):
    print(-1)
else:
    lo = 0
    hi = int(1e6)
    
    found = False
    right = int(1e18)
    left = int(1e18)
    bestSofar = int(1e18)
    
    while lo <= hi:
        val = f(lo) + f(hi)
        if val == K:
            if lo+hi+1 < bestSofar:
                bestSofar = lo+hi+1
                right = hi
                left = lo
            hi -= 1
            found = True
    
        elif val < K:
            lo += 1
            
        else:
            hi -= 1
    
    if not found:
        print(-1)
        
    else:
        leng = left + right + 1
        if left == 0:
            if right > 1000000:
                print(-1)
            else:
                print(right)
                lis = [0 for i in range(right)]
                print(*lis)

        else:
            if leng > 1000000:
                print(-1)
            else:
                print(leng)
                lis = [0 for i in range(left)] + [1] + [0 for i in range(right)]
                print(*lis)