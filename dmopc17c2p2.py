def isBalanced(s):
    left = 0
    right = 0

    leng = len(s)

    for i in range(leng):
        if s[i] == "(":
            left += 1
        else:
            right +=1 
        
        if right > left:
            return False

    return left == right

def solve():

    line = input()
    if isBalanced(line):
        print("YES")
    else:
        leng = len(line)
        left = 0
        right = 0
        for i in range(leng):
            if line[i] == "(":
                left += 1
            else:
                right += 1
    
            if right > left:
                line = line[0:i] + "(" + line[i+1: ]
                if isBalanced(line):
                    print("YES")
                else:
                    print("NO")
                return 

        if left == right + 2:
            print("YES")
        else:
            print("NO")
solve()