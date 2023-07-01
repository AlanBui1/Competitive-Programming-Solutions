n = int(input())

for i in range(n):
    word = input()
    
    cnt = 1 
    prev = word[0]
    ans = ""
    
    for k in range(1, len(word)):
        if word[k] == prev:
            cnt+=1
            
        else:
            ans+=str(cnt)+" "+prev+" "
            prev = word[k]
            cnt =1

    ans += str(cnt)+" "+prev
            
    print(ans)