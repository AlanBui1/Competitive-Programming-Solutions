m = int(input())
times = [0 for i in range(1442)]

for i in range(m):
    x, y = map(int, input().split())
    times[x] += 1
    times[1+y] -= 1
    
for i in range(1, 1442):
    times[i] += times[i-1]
    
n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    flag = 0
    for k in range(x, y+1):
        if times[k]:
            print("Break is Over! Stop playing games! Stop watching Youtube!")
            flag =1
            break
        
    if not flag:
        print(":eyy:")