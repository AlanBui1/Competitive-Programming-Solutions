def f(x):
    if x == 1:
        return 0
    if x%2 == 1:
        return f(x*3 + 1) + 1
    else:
        return f(x//2) + 1
        
n = int(input())
print(f(n))