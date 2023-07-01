n = int(input())
cipher = [input().split() for k in range(5)]
def NOTIN(let):
    for i in cipher:
        if let in i:
            return 0
    return 1
alpha = "abcdefghijklmnopqrstuvwxyz"
notIn = ""
for i in alpha:
    if NOTIN(i):
        notIn = i
        break

for i in range(n):
    line = input()
    k = 0
    while k < len(line):
        let = line[k]
        if let == notIn:
            print(let, end="")
            k += 1
            continue
        num = int(line[k+1])
        k += 2
        print(cipher[ord(let) - 65][num-1], end="")
    print()