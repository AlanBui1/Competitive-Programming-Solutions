import sys
input = sys.stdin.readline

powers = [1 for i in range(64)]
for i in range(1, 64):
    powers[i] = powers[i-1]*2
    
n = int(input())

for i in range(n):
    num = int(input())
    if num in powers:
        print("T")
    else:
        print("F")