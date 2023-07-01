e, n = map(int, input().split())
arr = [e] + [int(i) for i in input().split()]

powers = [[1 for i in range(11)]for k in range(11)]

for i in range(1, 11):
    for k in range(1, 11):
        powers[i][k] *= i
        powers[i][k] *= powers[i][k-1]

def toBase10(num, otherPow):
    ret = 0

    cur = 0
    while num > 0:
        ret += powers[otherPow][cur]*(num%10)
        num //= 10
        cur += 1

    return ret

prev =10
for i in range(n, -1, -1):
    arr[i] = toBase10(arr[i], prev)
    prev = arr[i]

print(arr[0])