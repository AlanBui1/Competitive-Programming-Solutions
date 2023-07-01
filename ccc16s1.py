word = input()
freq = [0 for i in range(26)]

for i in word:
    freq[ord(i)-97] += 1
    
word = input()
cnt = 0
for i in word:
    if i == "*":
        cnt += 1
        continue
    
    freq[ord(i)-97] -= 1
flag = False
left = 0
for i in range(26):
    if freq[i] < 0:
        flag = True
        break
    
    left += freq[i]
    
if flag:
    print("N")
else:
    print("A")