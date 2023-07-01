plain = input()
cipher = input()
msg = [i for i in input()]

conv = {}

for i in range(len(cipher)):
    conv[cipher[i]] = plain[i]

for i in range(len(msg)):
    try:
        msg[i] = conv[msg[i]]
    except:
        msg[i] = "."
print(*msg, sep="")