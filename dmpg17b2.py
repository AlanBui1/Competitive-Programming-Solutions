def solve():
    line = input()
    if line[0] == ",":
        print(line[2].upper()+line[3:])
        return
    punc = line[-1]
    line = line[:len(line)-1].split(",")
    line[1] = line[1][1:]

    if line[1] == "":
        print(line[0]+punc)
        return

    
    
    print(line[1][0].upper()+line[1][1:]+" "+line[0][0].lower()+line[0][1:]+punc)
    
solve()