import sys
input = sys.stdin.readline
n, k = map(int, input().split())
lis = [int(i) for i in input().split()]
lis.sort()

left = 0; right = 0
ans = 0
if k == 0:
    print(1)
else:
    while right < n:
        if lis[right]-lis[left] <= k:
            ans = max(ans, right-left +1 )
            right += 1
            

        else:
            left+=1

    print(ans)