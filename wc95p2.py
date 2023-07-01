k = int(input())
n = bin(k)[2:]
lim = len(n)

dp = [[[[-1 for i in range(33)]for k in range(33)]for j in range(33)]for l in range(2)]

def solve(index, flag, zeroes, ones, added):
    
    if index == lim:
        if zeroes >= ones:
        
            return 1
        return 0

    if dp[flag][index][ones][zeroes] != -1:
        return dp[flag][index][ones][zeroes]

    highest = 1
    if flag:
        highest = int(n[index])

    ret = 0
    for i in range(highest+1):
        ns = 0
        if i < int(n[index]):
            ns = 0
        else:
            ns = flag
        if i:
            ret += solve(index+1, ns, zeroes, ones+1, 1)

        else:
            if not added:
                ret += solve(index+1, ns, zeroes, ones, 0)
            else:
                ret += solve(index+1, ns, zeroes+1, ones, 1)

    dp[flag][index][ones][zeroes] = ret
    return ret

print("There are",solve(0, 1, 0, 0, 0)-1,"round numbers less than or equal to "+str(k)+".")