def solve():
    line = input()
    names = ["elpsycongroo", "tuturu", "superhacker", "myfork"]
    pointers = [0,0,0,0]
    leng = [len(i) for i in names]
    done = [0,0,0,0]
    conv = {"elpsycongroo" : "Okabe",
            "tuturu" : "Mayuri",
            "superhacker" : "Daru",
            "myfork" : "Kurisu"
           }

    for L in line:
        for i in range(4):
            if done[i]:
                continue
            if names[i][pointers[i]] == L:
                pointers[i] += 1
                if pointers[i] == leng[i]:
                    done[i] = 1
    ans = []
    for i in range(4):
        if done[i]:
            ans.append(names[i])

    if len(ans) == 0:
        print("SERN spy!")
    elif len(ans) == 1:
        print(conv[ans[0]])

    else:
        ans = [conv[ans[i]] for i in range(len(ans))]
        print(*ans, sep=" or ")

n = int(input())
for i in range(n):
    solve()