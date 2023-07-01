spicy = 0

numpeppers = int(input())

for i in range(numpeppers):
    pepper = input()

    #Way 1: (Naive) if statements
    if pepper == "Poblano":
        spicy += 1500
    if pepper == "Mirasol":
        spicy += 6000
    if pepper == "Serrano":
        spicy += 15500
    if pepper == "Cayenne":
        spicy += 40000
    if pepper == "Thai":
        spicy += 75000
    if pepper == "Habanero":
        spicy += 125000

print(spicy)