freq = [0 for i in range(26)]
line = input()
ans = 1
leng = len(line)
MOD = int(1e9)+7
for i in range(leng):
    freq[ord(line[i])-97] += 1

for i in freq:
    if i != 0:
        ans  *= i+1
        ans %= MOD
        
print((ans+MOD)%MOD)