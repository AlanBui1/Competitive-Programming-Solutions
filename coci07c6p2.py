n, l = map(int, input().split())

lis = []
for i in range(n):
    d, r, g = map(int, input().split())
    lis.append([d, r, g])

#lis.sort()

timesofar = 0
distsofar = 0
curlight = 0

for i in range(1, l+1):
    distsofar+=1
    timesofar+=1
    if distsofar == lis[curlight][0]:
        tim = timesofar
        redTime = lis[curlight][1]
        greenTime = lis[curlight][2]

        if redTime > timesofar:
            timesofar += (redTime-timesofar)
        else:
            red = True
            while tim >= 0:
                if red:
                    tim -= redTime
                    if tim < 0:
                        break
                    red = False
                else:
                    tim -= greenTime
                    if tim < 0:
                        break
                    red = True

            if red:
                timesofar -= tim
        
        curlight+=1

    if curlight == n:
        timesofar+=(l-i)
        break

print(timesofar)