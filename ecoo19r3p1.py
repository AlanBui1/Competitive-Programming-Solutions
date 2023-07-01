import sys; input = sys.stdin.readline

for _ in range(10):
    n = int(input())
    freq = [int(i) for i in input().split()]
    freq.sort()
    sieve = [0 for i in range(freq[-1]+1)]

    ans = 0
    for i in range(n):
        ans += sieve[freq[i]]
        x = freq[i]
        while x < freq[-1]+1:
            sieve[x] += 1
            x += freq[i]

    print(ans)