from datetime import datetime, timedelta

orig = input()
if int(orig) >= 60:
  if len(orig) == 3:
    orig = [int(orig[0]), int(orig[1: ])]
  else:
    orig = [int(orig[0:2]), int(orig[2: ])]  
  t = datetime(year=1, month=1, day=10, hour=orig[0], minute=orig[1])

else:
  t = datetime(year=1, month=1, day=10, hour=0, minute=int(orig))

ottawa = str(t)
victoria = str(t+timedelta(hours=-3))
edmonton = str(t+timedelta(hours=-2))
winnipeg = str(t+timedelta(hours=-1))
halifax = str(t+timedelta(hours=1))
stjohns = str(t+timedelta(hours=1, minutes=30))

ottawa=ottawa[11:13]+ottawa[14:16]
x=0
for i in range(4):
  if ottawa[i] != '0':
    break
  else:
    x+=1
ottawa=ottawa[x: ]

victoria=victoria[11:13]+victoria[14:16]
x=0
for i in range(4):
  if victoria[i] != '0':
    break
  else:
    x+=1
victoria=victoria[x: ]

edmonton=edmonton[11:13]+edmonton[14:16]
x=0
for i in range(4):
  if edmonton[i] != '0':
    break
  else:
    x+=1
edmonton=edmonton[x: ]

winnipeg=winnipeg[11:13]+winnipeg[14:16]
x=0
for i in range(4):
  if winnipeg[i] != '0':
    break
  else:
    x+=1
winnipeg=winnipeg[x: ]

halifax=halifax[11:13]+halifax[14:16]
x=0
for i in range(4):
  if halifax[i] != '0':
    break
  else:
    x+=1
halifax=halifax[x: ]

stjohns=stjohns[11:13]+stjohns[14:16]
x=0
for i in range(4):
  if stjohns[i] != '0':
    break
  else:
    x+=1
stjohns=stjohns[x: ]

print(ottawa, "in Ottawa")
print(victoria, 'in Victoria')
print(edmonton, "in Edmonton")
print(winnipeg, "in Winnipeg")
print(ottawa, 'in Toronto')
print(halifax, "in Halifax")
print(stjohns, "in St. John's")