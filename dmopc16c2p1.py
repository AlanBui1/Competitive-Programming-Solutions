n = int(input())

k = int(input())

conv = [-1, 0.5, 1, 5]

for i in range(k):
    p = int(input())
    n -= conv[p]

if n >= 0:
    print("Continue")
else:
    print("Return")