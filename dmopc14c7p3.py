n = int(input())
a, b = map(int, input().split())
lhs = [int(i) for i in input().split()]
rhs = [int(i) for i in input().split()]

freq = {}

for i in lhs:
    if i not in freq:
        freq[i] = 0
    freq[i] += 1

for i in rhs:
    if i not in freq:
        freq[i] = 0
    freq[i] += 1

for i in freq:
    if freq[i] == 2:
        n -= 1

print(n)