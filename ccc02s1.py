def output(pink, green, red, orange):
    print("# of PINK is",pink,"# of GREEN is",green,"# of RED is",red,"# of ORANGE is",orange)

costs = [int(input()) for i in range(4)]
want = int(input())

s = set()

def recur(has, curCost):
    if curCost == want:
        s.add(tuple(has))
        # output(has[0], has[1], has[2], has[3])

    for i in range(4):
        if costs[i] + curCost <= want:
            has[i] += 1
            recur(has, curCost + costs[i])
            has[i] -= 1
recur([0,0,0,0], 0)
MIN = 10000000
for i in s:
    output(i[0], i[1], i[2], i[3])
    MIN = min(MIN, i[0]+i[1]+i[2]+i[3])
print("Total combinations is",str(len(s))+".")
print("Minimum number of tickets to print is",str(MIN)+".")