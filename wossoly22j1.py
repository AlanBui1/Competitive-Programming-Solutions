import sys
input = sys.stdin.readline

n= int(input())
a, b, c = map(int, input().split())

cost = a + b*4 + c*7

if cost <= n:
    print("Time to go shopping!")
else:
    print("You cannot afford them all.")