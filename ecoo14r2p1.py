vals = [1,2,5,10,50,100,1000,10000,500000,1000000]
for _ in range(10):
    card = [input() for i in range(9)]
    unknown = card.count("?")
    for i in range(9):
        if card[i] != "?":
            card[i] = int(card[i][1: ])
    
    possible = []
    for i in range(10):
        if card.count(vals[i]) >= 3:
            possible = ["$"+str(vals[i])]
            break
        if card.count(vals[i]) + unknown >= 3:
            possible.append("$"+str(vals[i]))

    if len(possible) > 0:
        print(*possible)
    else:
        print('No Prizes Possible')