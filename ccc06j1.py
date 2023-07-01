lis = [[461, 431, 420,0], [100, 57, 70, 0], [130,160,118,0], [167,266,75,0]]
ans =0
for i in range(4):
    x = int(input())
    x -= 1
    ans += lis[i][x]

print("Your total Calorie count is", str(ans)+".")