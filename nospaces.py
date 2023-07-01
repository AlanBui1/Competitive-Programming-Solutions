lis = [int(i) for i in input()]
freq = {}
mostFreq = 0
num= int(1e14)
lim = len(lis)

def S(x, y):
    cur = 1
    ret=0
    for i in range(y, x-1, -1):
        ret += cur* lis[i]
        cur *= 10
    return ret
def solve(used, lastUsed, val, cur):
    global mostFreq, num
    if cur == lim:
        if not used or lastUsed != cur:
            return
        if val not in freq:
            freq[val] = 0

        freq[val] += 1
        if freq[val] > mostFreq:
            mostFreq = freq[val]
            num = val
        elif freq[val] == mostFreq:
            num = min(num, val)
       
        return
    solve(used, lastUsed, val, cur+1)
    solve(1, cur+1, val+S(lastUsed, cur), cur+1)

solve(0, 0, 0, 0)

print(len(freq), num, sep= "")