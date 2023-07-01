sentence = input()
n = len(sentence)
freq = [[0 for i in range(n)] for k in range(26)]
freq[ord(sentence[0])-97][0] +=1

for i in range(1, n):
    if sentence[i] == " ":
        for j in range(26):
            freq[j][i] += freq[j][i-1]
        continue

    freq[ord(sentence[i])-97][i] += 1

    for j in range(26):
        freq[j][i] += freq[j][i-1]

q = int(input())

for i in range(q):
    a, b, c = input().split()

    a = int(a)-1
    b = int(b)-1

    if a == 0:
        print(freq[ord(c)-97][b])

    else:
        print(freq[ord(c)-97][b] - freq[ord(c)-97][a-1])