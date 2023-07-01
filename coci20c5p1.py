word = input()
num = False
lis = {}
start = 0

for i in range(len(word)):
    if ord(word[i]) < 97:
        if not num:
            start = i
            num = True

    else:
        if num:
            lis[word[start:i]] = True
        num = False

if num:
    lis[word[start:]] = True
print(len(lis))