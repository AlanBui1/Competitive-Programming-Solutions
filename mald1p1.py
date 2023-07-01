def yubo(s):
    if "yubo" in s:
        return True
    return False

def solve():
    n = int(input())
    lis = []

    for i in range(n):
        x = input()
        lis.append(x)

    used = {}
    ans = []

    for i in range(n):   
        if lis[i] in used:
            continue
        Y = 0

        if yubo(lis[i]):
            Y = 1

        if i > 0:
            if yubo(lis[i-1]):
                Y = 1

        if i < n-1:
            if yubo(lis[i+1]):
                Y = 1
        if Y:
            used[lis[i]]= 1

    for i in used:
        ans.append(i)

    ans.sort()

    for i in ans:
        print(i)
            

solve()