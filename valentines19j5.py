n=  int(input())
freq = {}
pairs = {}

ans = 0

for i in range(n):
    m, b = map(int, input().split())

    if m not in freq:
        freq[m] = 0

    ans += i-freq[m]
    freq[m] += 1
    if (m, b) not in pairs:
        pairs[(m, b)] = 0
    ans += pairs[(m, b)]
    pairs[(m, b)] += 1
print(ans)