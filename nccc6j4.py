def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a*b//gcd(a, b)

def solve():
    n = int(input())

    lis = {}
    conv = {"Deluxe Tuna Bitz":4, "Bonito Bitz":3, "Sashimi":2, "Ritzy Bitz":1}
    rconv = {4:"Deluxe Tuna Bitz", 3:"Bonito Bitz", 2:"Sashimi", 1:"Ritzy Bitz"}
    for _ in range(n):
        name = input()
        if name not in lis:
            lis[name] = 0
        lis[name] += 1

    L = []
    for i in lis:
        L.append([lis[i], conv[i]])
    L.sort(reverse = True)
    for i in L:
        print(rconv[i[1]], i[0])
    
solve()