turns = 0
highest = 0

lis = [[int(i) for i in input().split()] for k in range(2)]
def rotate(LIST):
    ret = [[LIST[1][0], LIST[0][0]], [LIST[1][1], LIST[0][1]]]
    return ret

def val(LIST):
    return (LIST[0][0]/LIST[1][0]) + (LIST[0][1]/LIST[1][1])

for i in range(4):
    if val(lis) > highest:
        highest = val(lis)
        turns = i

    lis = rotate(lis)

print(turns)