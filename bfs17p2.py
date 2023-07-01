import sys; input = sys.stdin.readline

n = int(input())
lis = [i for i in input().split()]

freq = {"yellow": 0, "red":0, "green":0, "blue":0, "black":0, "orange":0}

for i in lis:
    freq[i] += 1

prev = ""
leng = 0

for i in range(n):
    most = 0
    nxt = ""
    for col in freq:
        if col == prev:
            continue
        if freq[col] > most:
            most = freq[col]
            nxt = col

    if most == 0:
        break
    freq[nxt] -= 1
    prev = nxt
    leng += 1

print(leng)