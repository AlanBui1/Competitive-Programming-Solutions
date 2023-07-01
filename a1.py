N = int(input())
z = 1
for i in range (0,N,1):
    word = input()
    M = int(word.index(' '))
    x = int(word[0:M])
    if x < 10:
        print(z,word[M+1:x+1]+word[x+2:])
    if x >= 10:
        print(z,word[M+1:x+2]+word[x+3:])
    z = z+ 1