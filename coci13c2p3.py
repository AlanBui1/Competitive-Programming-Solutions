x = int(input())
word = input()
orig = word
def blink(w):
    p1 = 0
    p2 = len(w)-1

    cnt = 0

    new = ""

    while cnt < len(w):
        cnt+=1

        if (cnt&1):
            new += w[p1]
            p1+=1
        else:
            new += w[p2]
            p2 -=1
    return new

lis = []
word = blink(word)
lis.append(word)

while word != orig:
    word = blink(word)
    lis.append(word)
leng = len(lis)
print(lis[(lis.index(orig)+leng-(x%leng))%leng])