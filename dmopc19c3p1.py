import sys
input = sys.stdin.readline

n = int(input())
a = [int(i) for i in input().split()]

freq = {}

highest = -1
for i in a:
    if i not in freq:
        freq[i] = 0
    freq[i] += 1

    highest = max(highest, freq[i])
lis = []

for i in freq:
    if freq[i] == highest:
        lis.append(i)
lis.sort()
print(*lis)