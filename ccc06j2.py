n = int(input())
m = int(input())
w = 0

if m > 10:
    m = 9
if n > 10:
    n = 9

w = m + n - 9
if w < 0:
    w = 0
    
if w == 1:
    print("There is 1 way to get the sum 10.")
else:
    print("There are",w,"ways to get the sum 10.")