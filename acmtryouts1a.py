x = int(input())

for x in range (0,x,1):
    p1 = input()
    if p1 == 'Scissors':
        print("Rock")
    if p1 == 'Rock':
        print("Paper")
    if p1 == 'Paper':
        print("Scissors")
    if p1 == 'Fox':
        print("Foxen")
    if p1 == 'Foxen':
        break