lis = [int(i) for i in input().split()]
lis.sort()

diffs = [lis[1] - lis[0], lis[2] - lis[1]]
if diffs[0] != diffs[1]:
    if diffs[0] > diffs[1]:
        print(lis[0]+diffs[1])
    else:
        print(lis[1]+diffs[0])
else:
    diff = diffs[0]
    print(lis[2] + diff)