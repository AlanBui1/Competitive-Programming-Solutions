lis = []

n, m, k, x = map(int, input().split())

word = input()

ops = [[k for k in input()] for i in range(m)]
for i in range(m):
    ops[i].sort()

inds = []
cnt = 0

for i in range(n):
    if word[i] == "#":
        inds.append(i)
        cnt += 1

inds.append(-1)

def power(a, x):
    base = a
    mult = a
    
    while x > 0:
        if x&1:
            base *= mult

        mult *= mult
        x//=2

    return base//a

def solve(curWord, ind, cur, left):
    if left == 0 or ind == -1:
        return curWord

    sub = power(k, cnt-cur-1)
    #print(sub, left)
    I = 0
    while left > sub:
        left -= sub
        I += 1

    if I >= k:
        I = k-1

    return solve(curWord[:ind]+ops[cur][I]+curWord[ind+1:], inds[cur+1], cur+1, left)

print(solve(word, inds[0], 0, x))