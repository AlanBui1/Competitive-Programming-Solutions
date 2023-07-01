val = {}
re = {}
for i in range(26):
    re[i] = chr(i+65)
    val[chr(i+65)] = i

message = [i for i in input()]
key = [i for i in input()]

def changeVal(letter):
    return val[letter]%26

new = []

for i in range(len(message)):
    new.append(re[(changeVal(message[i])-changeVal(key[i]))%26])
    key.append(new[i])

ans = ""
for i in range(len(new)):
    ans+=new[i]

print(ans)