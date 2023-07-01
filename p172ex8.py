freq = [0 for i in range(104)]

while 1:
    x = int(input())
    if x == -1:
        break
    
    freq[x] += 1
    
best = max(freq)
for i in range(104):
    if best == freq[i]:
        print(i)