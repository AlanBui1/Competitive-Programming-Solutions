n = int(input())
conv = {}
highest = 0
warn = 0

for i in range(n):
    line = input()
    if line not in conv:
        conv[line] = 0
    
    highest = 0
    for i in conv:
        if i != line:
            highest += conv[i]
    
    if conv[line] > highest:
        warn += 1
    
    conv[line] += 1 
    
print(warn)