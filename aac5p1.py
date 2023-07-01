import sys; input = sys.stdin.readline
n= int(input())

lis = [int(i)%2 for i in input().split()]

print(lis.count(1)//2 + lis.count(0)//2)