def solve():
    n = int(input())

    s = input()
    dna = sum([s.count(i) for i in "ACTG"])
    rna = sum([s.count(i) for i in "ACGU"])

    if dna == rna == n:
        print("both")
    elif dna == n:
        print("DNA")
    elif rna == n:
        print("RNA")
    else:
        print("neither")
    
solve()