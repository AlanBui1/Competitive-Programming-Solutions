# def check(lis, n):
    
    # found = [0 for i in range(n+1)]
    # for i in range(len(lis)):
    #     for k in range(1+i, len(lis)):
           
    #         if lis[i] + lis[k] <= n:
    #             found[lis[i] + lis[k]] = 1
           
    #         if lis[i] > lis[k]:
    #             found[lis[i] - lis[k]] = 1
        
    #         if lis[k] > lis[i]:
    #             found[lis[k] - lis[i]] = 1
          
    # # print(found)
    # return found.count(0) == 1


n, m = map(int, input().split())
flag = 0
for test in range(3, n):
    ans = [i for i in range(1, test+1)]
    ans.append(test + test + 1)
    while len(ans) < m:
        if ans[-1] + test+test+1 <= n:
            ans.append(test+test+1 + ans[-1])
        else:
            if ans[-1] + test <=n:
                ans.append(ans[-1] + test)
            else:
                break
                
    if ans[-1] + test >= n:
        flag = 1
        break

        
assert(len(ans) <= m)
# assert(check(ans, n))
print(len(ans))
print(*ans)