n = int(input())
bestname = "None"; bestscore = -1
for i in range(n):
    lis = input().split()
    name = lis[0]
    wins = int(lis[1])
    loss = int(lis[2])
    
    if loss == 0 and wins > bestscore:
        bestscore = wins
        bestname= name
        
print(bestname)