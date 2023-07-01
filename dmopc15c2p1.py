n= int(input())
r= int(input())
ans = n
swords = n
while swords//r > 0:
    ans += (swords//r)
    swords = (swords%r) + (swords//r)
print(ans)