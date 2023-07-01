from math import inf
n = int(input())
x, y, z = map(int, input().split())
lis = [-inf for i in range(n+1)]
lis[0] = 0
i=0

# for i in range(n+1):
#     if lis[i] != -1:
#         if (i+x) <= n:
#             lis[i+x] = max(lis[i+x], lis[i]+1)

#         if i+y <= n:
#             lis[i+y] = max(lis[i+y], lis[i]+1)

#         if i+z <= n:
#             lis[i+z] = max(lis[i+z], lis[i]+1)
for i in range(n+1):
    optx=opty=optz=-inf
    if i-x >= 0:
        optx = max(lis[i], lis[i-x]+1)

    if i-y >= 0:
        opty = max(lis[i], lis[i-y]+1)

    if i-z >= 0:
        optz = max(lis[i], lis[i-z]+1)
    lis[i] = max(lis[i], optx, opty, optz)
    
    
# for i in range(n+1):
#     if lis[i] != -1:
#         if (i+x) <= n:
#             lis[i+x] = max(lis[i+x], lis[i]+1)

# for i in range(n+1):
#     if lis[i] != -1:
#         if i+y <= n:
#             lis[i+y] = max(lis[i+y], lis[i]+1)

# for i in range(n+1):
#     if lis[i] != -1:
#         if i+z <= n:
#             lis[i+z] = max(lis[i+z], lis[i]+1)
if lis[n] == -inf:
    print(0)
else:
    print(lis[n])