def pos(word, idx, want):
    word = word[:idx]+want+word[idx+1:]
    cnt = 0
    for i in range(3):
        if word[i] == want:
            cnt += 1

    if cnt >= 3:
        return False

    for i in range(len(word)-3):
        if word[i] == want:
            cnt -= 1
        if word[i+3] == want:
            cnt += 1
        if cnt >= 3:
            return False
            
    if cnt >= 3:
        return False
    return True

def solve(curWord, mult, legal):
    ind = curWord.find("_")
    if ind == -1:
        if legal:
            return mult
        return 0
    
    ret = 0
    if pos(curWord, ind, "1"):
        ret += solve(curWord[:ind]+"1"+curWord[ind+1:], mult*5, legal)

    if pos(curWord, ind, "2"):
        ret += solve(curWord[:ind]+"2"+curWord[ind+1:], mult*20, legal) + solve(curWord[:ind]+"2"+curWord[ind+1:], mult, 1)

    return ret

word = input()
n = ""
startgood = 0
for i in word:
    if i == "L":
        n += "2"
        startgood =1

    elif i in "AEIOU":
        n += "1"

    elif i == "_":
        n += "_"
    else:
        n += "2"

print(solve(n, 1, startgood))