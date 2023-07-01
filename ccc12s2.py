line = input()
lis = []

def val(code):
    return int(code[0]) * conv[code[1]]

for i in range(0, len(line), 2):
    lis.append(line[i] + line[i+1])

conv = {
    "I":1,
    "V":5,
    "X":10,
    "L":50,
    "C":100,
    "D":500,
    "M":1000
}

ans = val(lis[-1])

for i in range(len(lis) - 1):
    if conv[lis[i+1][1]] > conv[lis[i][1]]:
        ans -= val(lis[i])
    else:
        ans += val(lis[i])
print(ans)