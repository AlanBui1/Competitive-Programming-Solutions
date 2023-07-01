k = [int(i) for i in input().split()]
s = 0
num = 0
z = 0
tot = []
for i in range(0,k[0],1):
  lis= [k for k in input().split()]
  num=num + int(lis[0])
  tot.append(int(lis[0])-int(lis[1]))
tot.sort(reverse = True)  
for i in range(0,k[1],1):
  num -= int(tot[i])
print(num)