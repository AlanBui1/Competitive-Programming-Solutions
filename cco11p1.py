n = int(input())

lis = [[float(i) for i in input().split()]for k in range(n)]

lis.sort(reverse = True)

want = int(input())

prev = 1


def bsearch(start, goal):
    lo = start
    hi = int(1e18)
    while (lo <= hi):
        mid = (lo+hi)//2
        avg = (start + mid)/ 2 
            
        if goal == avg:
            return mid

        if goal < avg:
            hi= mid-1
        else:
            lo = mid+1

for i in range(n):
    score, avg = lis[i]
    nxt = bsearch(prev, avg)

    if score == want:
        print(prev)
        print(nxt)
        break
    prev = nxt+1