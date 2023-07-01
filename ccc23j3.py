numppl = int(input())

pplgoing = [0,0,0,0,0] #number people going on day 1, day 2, ..., day 5

for i in range(numppl):
    avail = input()
    for d in range(5):
        if avail[d] == 'Y':
            pplgoing[d] += 1

mostppl = max(pplgoing)
bestdays = []

for day in range(5):
    if pplgoing[day] == mostppl:
        bestdays.append(day+1)

bestdays.sort()
print(*bestdays, sep=",")