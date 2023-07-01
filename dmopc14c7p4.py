n = int(input())

end = 200000000000
num = -1

l = 1
r = 200000

def f(x):
    return x*(x+1)//2

while l <= r:
    mid = (l+r)//2
    m = f(mid)

    if n > m:
        l = mid+1

    elif n == m:
        end = m
        num = mid
        break

    else:
        end = min(end, m)
        r = mid-1
        num = mid
A= end-num+1
B = end
print((A+B)*num//2)