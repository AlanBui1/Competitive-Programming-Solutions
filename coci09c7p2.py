import sys
input = sys.stdin.readline

k = int(input())
done = 0
bits = -1
for i in range(34):
    if (1 << i) > k:
        print(1 << i, end=" ")
        bits = i
        break
    elif (1 << i) == k:
        print(k, 0)
        done = 1
        break
        
if not done:
    for i in range(34):
        if k & (1 << i):
            last = i
            break
            
    print(bits-last)