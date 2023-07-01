line = input()
tot = 0
clubs = ["Clubs"]
diamonds = ["Diamonds"]
hearts = ["Hearts"]
spades = ["Spades"]

def bonus(lis):
    if len(lis) == 1:
        return 3
    elif len(lis) == 2:
        return 2
    elif len(lis) == 3:
        return 1
    else:
        return 0

pts = {"A": 4, "K": 3, "Q":2, "J":1}
c = d = h = s = 0

for i in range(1, line.index("D")):
    clubs.append(line[i])
    if line[i] in pts:
        c += pts[line[i]]
c += bonus(clubs)

for i in range(1+line.index("D"), line.index("H")):
    diamonds.append(line[i])
    if line[i] in pts:
        d += pts[line[i]]
d += bonus(diamonds)
for i in range(1+line.index("H"), line.index("S")):
    hearts.append(line[i])
    if line[i] in pts:
        h += pts[line[i]]
h += bonus(hearts)
for i in range(1+line.index("S"), len(line)):
    spades.append(line[i])
    if line[i] in pts:
        s += pts[line[i]]
s += bonus(spades)
print("Cards Dealt Points")
print(*clubs, c)
print(*diamonds, d)
print(*hearts, h)
print(*spades, s)
tot = c+d+h+s
print("Total", tot)