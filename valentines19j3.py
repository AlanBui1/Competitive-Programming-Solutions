line = [i for i in input()]
leng = len(line)

L = O = V = E = 0

for i in range(leng):
    if line[i] == "l":
        L += 1
    if line[i] == "o":
        O += L
    if line[i] == "v":
        V += O
    if line[i] == "e":
        E += V

print(E)