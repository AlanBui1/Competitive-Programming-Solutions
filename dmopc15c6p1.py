import math
cur = int(input())
want = int(input())
bonus = int(input())
exp = int(input())
cost = int(input())
want = want-cur
fish = 0
coins = 0

if want <= (bonus//exp)*3*exp:
    fish = want//(3*exp)
    if want % (3*exp) != 0:
        fish += 1

else:
    want -= (bonus//exp)*3*exp
    fish += (bonus//exp)
    
    if want > 0:
        want -= min(bonus - ((bonus//exp)*exp), exp) + (2*exp)
        fish+=1
    if want > 0:
        fish += (want//(2*exp))
        if want % (2*exp) != 0:
            fish +=1


coins = cost*fish

print(fish)
print(coins)