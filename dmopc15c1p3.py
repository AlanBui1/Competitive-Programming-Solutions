s = input()
t = input()

def shift(x):
    ret = ""
    for i in s:
        ret += chr((ord(i) + x - 97 + 26 + 26)%26 + 97)
    return ret

for i in range(26, -1, -1):
    newstring = shift(i)
    if t in newstring:
        print(26 - i)
        print(newstring)
        break