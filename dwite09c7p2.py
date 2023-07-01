from math import sqrt
lis = [2]
def isPrime(num):
    for i in range(3, int(sqrt(num))+1,2):
        if num%i == 0:
            return False

    return True
for i in range(3, 100000, 2):
    if isPrime(i):
        lis.append(i)
for _ in range(5):
    n = int(input())
    ans =0 
    for i in lis:
        if i > n:
            break

        ans += i

    print(ans)