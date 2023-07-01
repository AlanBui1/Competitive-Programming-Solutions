n = int(input())
graph = {}
lis = []

for i in range(n):
    webname = input()
    graph[webname] = []
    lis.append(webname)
    while True:
        line = input()
        if line == "</HTML>":
            break
        if '<A HREF="' not in line:
            continue
        line = line.split('<A HREF="')
        # line = '<A HREF="http://www.www.www.com">hello</A><A HREF="http://xxx">bye</A>'.split('<A HREF="')

        for block in line:
            if '"' not in block:
                continue
            cur = ""
            p = 0
            while block[p] != '"' and p < len(block):
                cur += block[p]
                p += 1
                
            print("Link from", webname, "to", cur)

            graph[webname].append(cur)
            
            if cur not in graph:
                lis.append(cur)
                graph[cur] = []
       
def dfs(cur):
    visited[cur] = True
    for nxt in graph[cur]:
        if not visited[nxt]:
            dfs(nxt)

while True:
    start = input()
    if start == "The End":
        break
    stop = input()

    visited = {name : False for name in lis}

    dfs(start)

    if visited[stop]:
        print("Can surf from", start, "to", stop+".")
    else:
        print("Can't surf from", start, "to", stop+".")