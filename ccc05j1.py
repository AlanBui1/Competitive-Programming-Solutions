a = int(input())
b = int(input())
c = int(input())

if a > 100:
  a1 = (a-100)*25
else: 
  a1 = 0
if a >250:
  a2 = (a-250)*45
else:
  a2 = 0

print('Plan A costs',"%.2f" %((a1+(b*15)+(c*20))/100))
print('Plan B costs',"%.2f" %((a2+(b*35)+(c*25))/100))

if (a2+(b*35)+(c*25))/100 < (a1+(b*15)+(c*20))/100:
  print('Plan B is cheapest.')
elif (a1+(b*15)+(c*20))/100 < (a2+(b*35)+(c*25))/100:
  print('Plan A is cheapest.')
else:
  print('Plan A and B are the same price.')