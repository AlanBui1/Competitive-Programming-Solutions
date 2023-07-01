n, k = map(int, input().split())
name = input()

freq = [0 for i in range(26)]
cnt = 0

for i in name:
    if i != "*":
        if freq[ord(i)-97] == 0:
            cnt += 1
        freq[ord(i)-97] += 1

factorials = [1]
for i in range(1, n+1):
    factorials.append(i*factorials[i-1])

if k == 0:
    ans = factorials[n]
    for i in freq:
        ans //= factorials[i]
    print(ans)

elif k == 1:
    fans = 0
    for i in range(26):
        ans = factorials[n]

        freq[i] += 1
        for k in freq:
            ans //= factorials[k]

        freq[i] -= 1
        fans += ans

    print(fans)

else:
    fans = 0
    for i in range(26):

        freq[i] += 1
        for k in range(i, 26):
            ans = factorials[n]

            freq[k] += 1
            for j in freq:
                ans //= factorials[j]
            freq[k] -= 1

            fans += ans

        freq[i] -= 1


    print(fans)