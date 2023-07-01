lis = [[int(i) for i in input().split()] for k in range(3)]
freq = {}
for i in range(3):
    if lis[i][0] not in freq:
        freq[lis[i][0]] = 0
    freq[lis[i][0]] += 1
for i in freq:
    if freq[i] == 1:
        X = i

freq = {}
for i in range(3):
    if lis[i][1] not in freq:
        freq[lis[i][1]] = 0
    freq[lis[i][1]] += 1
for i in freq:
    if freq[i] == 1:
        Y = i

print(X, Y)