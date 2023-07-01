MOD = 1000000000

a, b, n = map(int, input().split())

def multiply(lis, old):

    newmatrix = [[0 for i in range(2)] for k in range(2)]

    for i in range(2):
        for j in range(2):
            for k in range(2):
                newmatrix[i][j] += lis[i][k]*old[k][j]
                newmatrix[i][j] %= MOD

    return newmatrix

mult = [[1, 1],
        [1, 0]]
matrix = [[a+b, b],
          [b, a]]

while n > 0:
    
    if (n&1):
        matrix = multiply(matrix, mult)
    n//=2
    mult = multiply(mult, mult)  
  

print(matrix[1][1]%MOD)