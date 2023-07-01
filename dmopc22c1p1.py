import sys
input = sys.stdin.readline

def works(lis, n):
    if lis[0] < lis[1]:
        for i in range(n-1):
            if i%2 == 0:
                if lis[i] >= lis[i+1]:
                    return False

            else:
                if lis[i] <= lis[i+1]:
             
                    return False

        return True
    elif lis[0] > lis[1]:
        for i in range(n-1):
            if i%2 == 1:
                if lis[i] >= lis[i+1]:
                   
                    return False

            else:
                if lis[i] <= lis[i+1]:
          
                    return False
        return True
    else:
        return False

def test(lis, n):
    if lis[0] < lis[1]:
        for i in range(n):
            if lis[i] == 0:
                if i%2 == 1:
                    lis[i] = int(1e9)+1
                else:
                    lis[i] = -1

        if works(lis, n):
            return True
        return False

    elif lis[0] > lis[1]:
        for i in range(n):
            if lis[i] == 0:
                if i%2 == 0:
                    lis[i] = int(1e9)+1
                else:
                    lis[i] =-1


        if works(lis, n):
            return True
        return False
    else:
        return False

def solve():
    n = int(input())
    lis = [int(i) for i in input().split()]

    if lis.count(0) == 0:
        if works(lis, n):
            print("YES")
        else:
            print("NO")

        return

    for i in range(n):
        if lis[i] == 0:
            testlis = lis[:]
            testlis[i] = int(1e9)+1
            if test(testlis, n):
                print("YES")
                return

            lis[i] = -1
            if test(lis, n):
                print("YES")
                return
            print("NO")
            return 
        

    
t = int(input())
for _ in range(t):
    solve()