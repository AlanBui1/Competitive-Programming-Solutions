d = int(input())
lis = [1, 5, 10, 100,500,1000]

cur = 5
ans = [0,0,0,0,0,0,0]


if d >= 1000:
    ans[6] += d//1000
    d %= 1000

if d >= 500:
    ans[5] += d//500
    d %= 500

if d >= 100:
    ans[4] += d//100
    d %= 100

if d >= 50:
    ans[3] += d//50
    d %= 50

if d >= 10:
    ans[2] += d//10
    d%= 10

if d >= 5:
    ans[1] += d//5
    d%=5

if d >= 1:
    ans[0] += d//1
    
print(*ans)