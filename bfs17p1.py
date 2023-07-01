n = int(input())
num=0
word = [k for k in input().split()]

for i in range(len(word)):
    if len(word[i]) > 10:
        continue
    num+=1
     
print(num)