n, t= map(int, input().split())

longest = int(2e9)
name = ""

for i in range(n):
    NAME, dist = map(str, input().split())
    dist = int(dist)
    
    if abs(dist - t) < longest:
        longest = abs(dist-t)
        name = NAME
    
print(name)