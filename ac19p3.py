line = input().split()
if len(line) == 1:
    print(line[0])
else:
    ans = 0
    
    for _ in range(len(line)):
        i = line[_]
        if '+' not in i and '(' not in i and ')' not in i:
            ans += int(i)
    
        else:
            add = ""
            for x in i:
                if x in "0123456789-":
                    add += x
    
            if len(add) > 0:
                ans += int(add)
    print(ans)