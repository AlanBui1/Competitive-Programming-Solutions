k = int(input())
conv = {}
for i in range(k):
    a, b = input().split()
    conv[b] = a
line = input()
n = len(line)
cur = 0
curString = ""
while cur < n:
    if curString in conv:
        print(conv[curString],end="")
        curString = ""
    curString += line[cur]
    cur += 1

print(conv[curString])