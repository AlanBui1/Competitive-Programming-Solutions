j = int(input())
A= int(input())

'''
S = 1
M = 2
L = 3
'''

conv = {'S': 1, 'M': 2, 'L': 3}

sizes = [conv[input()] for i in range(j)]

ans = 0
for i in range(A):
    a, b = input().split()
    a = conv[a]
    b = int(b)

    if sizes[b -1] >= a:
        sizes[b-1] = -1
        ans += 1
    

print(ans)