n = int(input())
lis = {}
words = []
for i in range(n):
    word = input()
    try:
        lis[word[0]].append(word)
    except:
        lis[word[0]] = [word]
        
    if word[0] not in words:
        words.append(word[0])
        
words.sort()
for w in words:
  
    lis[w].sort()
    ans = ""
    for i in range(len(lis[w])-1):
        ans+=lis[w][i]
        ans+=", "
    ans+=lis[w][-1]
    print(ans)