n = int(input())
ans = str(n)+" cents requires "
if n == 1:
    ans = str(n)+" cent requires "
if n//25 > 0:
    if n//25 == 1:
        ans += str(n//25) + " quarter, "
    else:
        ans += str(n//25) + " quarters, "
    n -= (n//25)*25
    
if n//10 > 0:
    if n // 10 == 1:
        ans += str(n//10) + " dime, "
    else:
        ans += str(n//10) + " dimes, "
    n -= (n//10)*10
    
if n//5 > 0:
    if n//5 == 1:
        ans += str(n//5) + " nickel, "
    else:
        ans += str(n//5) + " nickels, "
    n -= (n//5)*5
    
if n > 0:
    if n == 1:
        ans += str(n) + " cent, "
    else:
        ans += str(n) + " cents, "


print(ans[:ans.rfind(",")]+".")