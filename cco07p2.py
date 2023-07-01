n = int(input())
lis = {}
found = False
for i in range(n):
  snow = [k for k in input().split()]
  if snow[0]+snow[1]+snow[2]+snow[3]+snow[4]+snow[5] in lis:
    found = True
  elif snow[1]+snow[2]+snow[3]+snow[4]+snow[5]+snow[0] in lis:
    found = True
  elif snow[2]+snow[3]+snow[4]+snow[5]+snow[0]+snow[1] in lis:
    found = True
  elif snow[3]+snow[4]+snow[5]+snow[0]+snow[1]+snow[2] in lis:
    found = True
  elif snow[4]+snow[5]+snow[0]+snow[1]+snow[2]+snow[3] in lis:
    found = True
  elif snow[5]+snow[0]+snow[1]+snow[2]+snow[3]+snow[4] in lis:
    found = True
  elif snow[5]+snow[4]+snow[3]+snow[2]+snow[1]+snow[0] in lis:
    found = True
  elif snow[4]+snow[3]+snow[2]+snow[1]+snow[0]+snow[5] in lis:
    found = True
  elif snow[3]+snow[2]+snow[1]+snow[0]+snow[5]+snow[4] in lis:
    found = True
  elif snow[2]+snow[1]+snow[0]+snow[5]+snow[4]+snow[3] in lis:
    found = True
  elif snow[1]+snow[0]+snow[5]+snow[4]+snow[3]+snow[2] in lis:
    found = True
  else:
    lis[snow[0]+snow[1]+snow[2]+snow[3]+snow[4]+snow[5]] = True
    lis[snow[5]+snow[4]+snow[3]+snow[2]+snow[1]+snow[0]] = True
    
if not found:
  print('No two snowflakes are alike.')
else:
  print('Twin snowflakes found.')