m = int(input())
n = int(input())
translate = {"1":"1", "2":"0", "3":"0", "4":"0", "5":"0", "6":"9", "7":"0", "8":"8", "9":"6", "0":"0"}

def flipped(num):
    num = str(num)
    num = num[::-1]
    new = ""
    for n in num:
        new += translate[n]

    return new
    
ans = 0
for i in range(m, n+1):
    if flipped(i) == str(i):
        ans+=1

print(ans)