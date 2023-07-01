import sys; 
input = sys.stdin.readline

n = int(input())
a= [int(i) for i in input().split()]

duke = 0
alice = 0

for i in a:
    if i%2 == 0:
        duke += i//2
    else:
        alice += (i+1)//2

if duke > alice:
    print("Duke")
else:
    print("Alice")