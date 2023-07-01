lis = [int(i) for i in "9780921418"]
for i in range(3):
    lis.append(int(input()))

mult = [1, 3]
ans = 0
for i in range(13):
    ans += mult[i%2]*lis[i]

print("The 1-3-sum is",ans%1000)