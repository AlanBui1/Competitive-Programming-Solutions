s, t = map(int, input().split())

str1 = input()
str2 = input()
ans = 0

freq = [0 for i in range(26)]

for i in range(s):
    freq[ord(str1[i])-65] += 1

used = 0
minused = 1e9
for i in range(t):
    if freq[ord(str2[i])-65]:
        ans += freq[ord(str2[i])-65]
        used += 1
    minused = min(minused, freq[ord(str2[i])-65])

if used != t:
    ans += max(freq)
else:
    ans += max(freq)
    ans -= minused
print(ans)