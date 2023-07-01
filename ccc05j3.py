lis=[]
while True:
    d = input()
    st = input()
    if st == 'SCHOOL':
      lis.append(d)
      break
    else:
        lis.append([d,st])

for i in range(len(lis)-2,-1,-1):
  if lis[i+1][0] == 'R':
    print('Turn LEFT onto', lis[i][1],'street.')
  else:
    print('Turn RIGHT onto', lis[i][1],'street.')

if lis[0][0] == 'R':
  print('Turn LEFT into your HOME.')
else:
  print('Turn RIGHT into your HOME.')