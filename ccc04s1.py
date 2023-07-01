n = int(input())
for i in range(n):
  lin1 = [k for k in input()]
  lin2 = [k for k in input()]
  lin3 = [k for k in input()]
  if lin1 != lin2[(len(lin2)-len(lin1)): ] and lin1 != lin3[(len(lin3)-len(lin1)): ] and lin2 != lin1[((len(lin1)-len(lin2))): ] and lin2 != lin3[((len(lin3)-len(lin2))): ] and lin3 != lin2[(len(lin2)-len(lin3)): ] and lin3 != lin1[(len(lin1)-len(lin3)): ] and lin1 != lin2[0:len(lin1)] and lin1 != lin3[0:len(lin1) ] and lin2 != lin1[0:len(lin2) ] and lin2 != lin3[0:len(lin2) ] and lin3 != lin2[0:len(lin3) ] and lin3 != lin1[0:len(lin3)]:
    print('Yes')
  else:
    print('No')