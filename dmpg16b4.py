import math
import sys; input = sys.stdin.readline

def fastPower(n, x):
    orig = n
    mult = n
    while x > 0:
        if x&1:
            n *= mult

        mult *= mult
        x //= 2

    return n//orig

def f(x):
    power = math.floor(math.log(x, 10))+1

    val = 0
    while x > 0:
        lastDigit = x%10
        if lastDigit != 0:
            val += fastPower(lastDigit, power)
        x//=10

    return val
    

def solve():
    history = []
    m = int(input())
    val = f(m)
    while m not in history:
        history.append(m)
        m = val
        val = f(m)
        
    leng = len(history)

    if m == f(m):     
        print("Equilibrium: Bob's investment becomes $"+str(m),"after", leng-1,"second(s)!")
    else:
        print("Instability: Loop of length", leng-history.index(m),"encountered after", history.index(m), "second(s)!")

t = int(input())
for _ in range(t):
    solve()