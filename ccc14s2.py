n = int(input())

names = input().split()
names2 = input().split()

partner = {}

for i in range(n):
    partner[names[i]] = names2[i]
    
flag = 0
for i in range(n):
    if partner[names[i]] == names[i] or partner[names2[i]] == names2[i]:
        flag = 1
        break
    if partner[partner[names[i]]] != names[i]:
        flag = 1
        break
        
if flag:
    print("bad")
else:
    print("good")