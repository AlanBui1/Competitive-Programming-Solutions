lin1 = input()
lin2 = input()
lin3 = input()
x=0
y=0

if lin1 == 'OOO':
  x=1
elif lin2 == 'OOO':
  x=1
elif lin3 == 'OOO':
  x=1
elif lin1[0] == 'O' and lin2[0] == 'O' and lin3[0] == 'O':
  x=1
elif lin1[1] == 'O' and lin2[1] == 'O' and lin3[1] == 'O':
  x=1
elif lin1[2] == 'O' and lin2[2] == 'O' and lin3[2] == 'O':
  x=1
elif lin1[0] == 'O' and lin2[1] == 'O' and lin3[2] == 'O':
  x=1
elif lin1[2] == 'O' and lin2[1] == 'O' and lin3[0] == 'O':
  x=1

if lin2 == 'XXX':
  y=1
elif lin1 == 'XXX':
  y=1
elif lin3 == 'XXX':
  y=1
elif lin1[0] == 'X' and lin2[0] == 'X' and lin3[0] == 'X':
  y=1
elif lin1[1] == 'X' and lin2[1] == 'X' and lin3[1] == 'X':
  y=1
elif lin1[2] == 'X' and lin2[2] == 'X' and lin3[2] == 'X':
  y=1
elif lin1[0] == 'X' and lin2[1] == 'X' and lin3[2] == 'X':
  y=1
elif lin1[2] == 'X' and lin2[1] == 'X' and lin3[0] == 'X':
  y=1

if x == 1 and y == 1:
  print("Error, redo")
elif y == 1:
  print('Timothy')
elif x == 1:
  print('Griffy')
else:
  print('Tie')