n = int(input())
for i in range(n):
    ends=[]
    for k in range(4):
        line = input().split()[-1].lower()
        ind =0
        for l in "aeiou":
            ind = max(ind, line.rfind(l))
            
        ends.append(line[ind: ])
        
    if ends.count(ends[0]) == 4:
        print("perfect")
    elif ends[0]==ends[1] and ends[2]==ends[3]:
        print("even")
    elif ends[0]==ends[3] and ends[1]==ends[2]:
        print("shell")
    elif ends [0]== ends[2] and ends[1]==ends[3]:
        print("cross")
    else:
        print("free")