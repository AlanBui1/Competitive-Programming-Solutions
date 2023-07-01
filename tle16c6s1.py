T = int(input())
lis = [input() for i in range(T)]
stuff = {i : [] for i in lis}
N = int(input())
for i in range(N):
    stuff[input()].append(i+1)
    
for i in lis:
    for k in stuff[i]:
        print(k)