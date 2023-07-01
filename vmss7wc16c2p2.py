import sys
input = sys.stdin.readline

G = input()
prefix = [0 for i in range(len(G))]
for i in range(1, len(G)):
    if G[i-1] == "G":
        prefix[i] +=1
    prefix[i] += prefix[i-1]
q = int(input())
for i in range(q):
    l, r = map(int, input().split())
    print(prefix[r+1] - prefix[l])