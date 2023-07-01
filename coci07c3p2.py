binary = input()
while len(binary) %3 != 0:
    binary = "0"+binary

conv = ["000", "001", "010", "011", "100", "101", "110", "111"]
ans = ""
for i in range(len(binary)//3):
    curString = binary[i*3: (i+1)*3]
    for k in conv:
        if k == curString:
            ans += str(conv.index(k))
            break

print(ans)