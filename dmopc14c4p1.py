line = input()
alphabet = [chr(i+65) for i in range(26)]
conv1 = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P']
C1 = {conv1[i] : alphabet[i] for i in range(26)}
ans = [C1[i] for i in line]
for i in range(len(line)):
    if line[i] == "0":
        ans[i] = "9"
    else:
        ans[i] = alphabet[(alphabet.index(ans[i])-1+26)%26]

print(*ans, sep="")