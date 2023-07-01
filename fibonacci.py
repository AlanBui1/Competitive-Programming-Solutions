MOD = 1000000007

n = int(input())



def multiply(lis, old):

    newmatrix = [[0 for i in range(2)] for k in range(2)]

    for i in range(2):
        for j in range(2):
            for k in range(2):
                newmatrix[i][j] += lis[i][k]*old[k][j]
                newmatrix[i][j] %= MOD

    return newmatrix
    
mult = [[1, 1],[1,0]]
matrix = [[1, 0],
          [0, 1]]

while n > 0:
    
    if (n&1):
        matrix = multiply(matrix, mult)
    n//=2
    mult = multiply(mult, mult)  

print(matrix[0][1]%MOD)