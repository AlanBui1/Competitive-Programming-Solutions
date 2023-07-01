n = int(input())
lis = [int(i) for i in input().split()]
mostFreq = -1
cnt = 0
for i in lis:
    x = lis.count(i)
    if x > cnt:
        cnt = x
        mostFreq = i
    elif x == cnt:
        mostFreq = min(mostFreq, i)
print(mostFreq)