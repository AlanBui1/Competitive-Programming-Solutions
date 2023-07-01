import sys
input = sys.stdin.readline

n, q= map(int, input().split())

arr = [int(i) for i in input().split()]
pref = [[] for i in range(n)]
suf = [[] for i in range(n)]

pref[0] = [arr[0], 1]
suf [n-1] = [arr[n-1], n]

for i in range(1, n):
    if pref[i-1][0] < arr[i]:
        pref[i] = [arr[i], i+1]

    else:
        pref[i] = pref[i-1]

for i in range(n-2, -1, -1):
    if suf[i+1][0] < arr[i]:
        suf[i] = [arr[i], i+1]
    
    else:
        suf[i] = suf[i+1]

for i in range(q):
    split = int(input())
    split -= 1
    print(pref[split-1][1], suf[split+1][1])