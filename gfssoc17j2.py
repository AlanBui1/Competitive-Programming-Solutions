score = 0
for i in range(6):
    score += float(input())
score /= 6
score += float(input())

req = float(input())

if req > score:
    print("no")
else:
    print("yes")