n = int(input())
lis = [0]+[int(i) for i in input().split()]

def merge(lis1, lis2, lis3):
    return lis3+lis1+lis2

def recur(L, R):
    if L == R:
        return [lis[L]]
    leng = R - L + 1
    return merge(recur(L, L + leng//3 -1), recur(L + leng//3, L + 2*leng//3 -1), recur(L+2*leng//3, R))

print(*recur(1, n))