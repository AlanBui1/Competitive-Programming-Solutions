n = int(input())
lis = {(1, 2, 3, 4): True, (0, 1, 1, 1): True, (0, 1, 2, 3): True, (0, 1, 3, 5): True, (0, 1, 4, 7): True, (0, 1, 5, 9): True, (0, 2, 1, 0): True, (0, 2, 2, 2): True, (0, 2, 3, 4): True, (0, 2, 4, 6): True, (0, 2, 5, 8): True, (0, 3, 2, 1): True, (0, 3, 3, 3): True, (0, 3, 4, 5): True, (0, 3, 5, 7): True, (0, 4, 2, 0): True, (0, 4, 3, 2): True, (0, 4, 4, 4): True, (0, 4, 5, 6): True, (0, 5, 3, 1): True, (0, 5, 4, 3): True, (0, 5, 5, 5): True, (0, 6, 3, 0): True, (0, 6, 4, 2): True, (0, 6, 5, 4): True, (0, 7, 4, 1): True, (0, 7, 5, 3): True, (0, 8, 4, 0): True, (0, 8, 5, 2): True, (0, 9, 5, 1): True, (1, 1, 1, 1): True}

hour1 = 1
hour2 = 2
minute1=0
minute2 = 0
ans = 0
ans += (n//720)*31
for i in range(n%720):
  minute2+=1
  if minute2 == 10:
    minute1+=1
    minute2=0
  if minute1==6:
    hour2+=1
    minute1=0
  if hour2==10:
    hour1+=1
    hour2=0
  if hour1 == 1 and hour2 == 3:
    hour1 = 0
    hour2 = 1
  if (hour1, hour2, minute1, minute2) in lis:
    ans+=1

print(ans)