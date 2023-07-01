lis = {}  
A=input()
lis["A"] = A
B=input()
lis["B"] = B
C=input()
lis["C"] = C
D=input()
lis["D"] = D
E=input()
lis["E"] = E
F=input()
lis["F"] = F
G=input()
lis["G"] = G
H=input()
lis["H"] = H
I=input()
lis["I"] = I
J=input()
lis["J"] = J
K=input()
lis["K"] = K
L=input()
lis["L"] = L
M=input()
lis["M"] = M
N=input()
lis["N"] = N
O=input()
lis["O"] = O
P=input()
lis["P"] = P
Q=input()
lis["Q"] = Q
R=input()
lis["R"] = R
S=input()
lis["S"] = S
T=input()
lis["T"] = T
U=input()
lis["U"] = U
V=input()
lis["V"] = V
W=input()
lis["W"] = W
X=input()
lis["X"] = X
Y=input()
lis["Y"] = Y
Z=input()
lis["Z"] = Z
_=input()
lis["_"] = _

n = int(input())
word = input()

alrSolved = {}
ans = ""
for letter in word:
    if letter in alrSolved:
        ans+=alrSolved[letter]
        continue
    
    stops = {}
    used = {}
    used[letter] = True
    stops[0] = letter
    count = 1
    calculating = lis[letter]
    
    while count<n+1 and calculating not in used:
        stops[count] = calculating
        used[calculating] = True
        count += 1
        calculating = lis[calculating]
        
    alrSolved[letter] = stops[n%count]
    ans += alrSolved[letter]

print(ans)