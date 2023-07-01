n = int(input())
k = int(input())

tot = n

for i in range(k):
    n *= 10
    tot += n
    
print(tot)