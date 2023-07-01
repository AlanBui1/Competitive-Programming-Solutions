op = input()
a, b, c = map(float, input().split())
x, y, z =map(float, input().split())

def s(m, n):
    return 1 - ((1-m)*(1-n))
    
def f(m, n):
    if m  < 0.5:
        return 2*m*n
        
    return 1- (2*(1 - m)*(1-n))

if op == "Multiply":
    print(a*x, b*y, c*z)
    
elif op == "Screen":
    print(s(a, x), s(b, y), s(c, z))
    
else:
    print(f(a, x), f(b, y), f(c, z))