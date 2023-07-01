import sys
input = sys.stdin.readline

n = int(input())
graph = [[] for i in range(n)]
# graph2 = [[] for i in range(n)]

while True:
    x, y = map(int, input().split())
    if x == 0 and y == 0:
        break
    # graph[x-1].append(y-1)
    graph[y-1].append(x-1)

mem = {0:1}

def solve(curNode):
    # print(curNode)

    if curNode in mem:
        return mem[curNode]

    else:
        for nxt in graph[curNode]:
            solve(nxt)
        mem[curNode] = sum([solve(nxt) for nxt in graph[curNode]])

solve(n-1)
print(mem[n-1])