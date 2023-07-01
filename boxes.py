import sys
input =sys.stdin.readline

n=int(input())
heights = [0 for i in range(1000005)]

for i in range(n):
    w, h = map(int, input().split())
    heights[w] = max(heights[w], h)
    
print(sum(heights))