wins = 0
for i in range(6):
    if input() == "W":
        wins += 1
        
if wins == 0:
    print(-1)
elif wins < 3:
    print(3)
elif wins < 5:
    print(2)
else:
    print(1)