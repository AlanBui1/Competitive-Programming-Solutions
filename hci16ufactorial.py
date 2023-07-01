factorials = [1]
for i in range(1, 21):
    factorials.append(i*factorials[i-1])
sentence = input()
flag = 0
for i in range(20, -1, -1):
    if sentence.count(str(i)+"!") > 0:
        print(factorials[i])
        flag = True
        break
if not flag:
    print(-1)