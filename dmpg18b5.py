word = input()
leng = int(input())
LEN = len(word)

p1 = 0
p2 = -1
freq = [0 for i in range(27)]
cnt = 0
ans = 0

for i in range(leng):
    if freq[ord(word[i]) -97] == 0:
        cnt += 1

    freq[ord(word[i])-97] += 1

for i in range(LEN-leng):
    if cnt == 1:
        ans += 1

    freq[ord(word[i])-97] -= 1
    if freq[ord(word[i])-97] == 0:
        cnt -= 1
    freq[ord(word[i+leng])-97] += 1
    if freq[ord(word[i+leng])-97] == 1:
        cnt += 1
if cnt == 1:
    ans += 1
print(ans)