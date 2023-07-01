highCards = ["king", "ace", "queen", "jack"]
flips = [3, 4, 2, 1]
p = ["A", "B"]
def isHigh(card):
    return card in highCards

def noHigh(L, R):
    for i in range(L, min(52, R+1)):
        if isHigh(cards[i]):
            return False

    return True

cards = [input() for i in range(52)]
tot = [0, 0]

for i in range(52):
    if isHigh(cards[i]):
        if 51 - i >= flips[highCards.index(cards[i])]:
            if noHigh(i+1, i+flips[highCards.index(cards[i])]):
                tot[i%2] += flips[highCards.index(cards[i])]
                print("Player",p[i%2]+" scores", flips[highCards.index(cards[i])], "point(s).")

print("Player A:", tot[0], "point(s).")
print("Player B:", tot[1] ,"point(s).")