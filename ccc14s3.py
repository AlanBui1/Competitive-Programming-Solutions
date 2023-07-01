import sys; input =sys.stdin.readline

t=int(input())

for _ in range(t):
    n =int(input())
    
    lis= [int(input()) for i in range(n)]
    lis.reverse()
    branch = []
    want = 1

    flag = False
    
    for i in range(n):
        if branch != []:
            while branch[-1] == want:
                want += 1
                del branch[-1]
                if branch == []:
                    break

        if lis[i] == want:
            want += 1

        else:
            branch.append(lis[i])

    branch.reverse()
    for i in branch:
        if i == want:
            want += 1

        else:
            flag= True

    if flag:
        print("N")
    else:
        print("Y")