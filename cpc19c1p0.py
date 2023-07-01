lis = input().split()

ans = []
ans.append([lis.index("L"), lis.index("R")])

lis[lis.index("L")] = -1
lis[lis.index("R")] = -1

ans.append([lis.index("L"), lis.index("R")])

for a, b in ans:
    print(a+1, b+1)