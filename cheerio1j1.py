vowel = "aeiou"

word = input()

flag = 1

if word[0] in vowel:
    for i in range(len(word)):
        if i%2 == 0:
            if word[i] not in vowel:
                flag = 0
                break
            
        else:
            if word[i] in vowel:
                flag = 0 
                break
            
    if flag:
        print("YES")
    else:
        print("NO")
        
else:
    for i in range(len(word)):
        if i%2 == 0:
            if word[i] in vowel:
                flag = 0
                break
        else:
            if word[i] not in vowel:
                flag = 0
                break
            
    if flag:
        print("YES")
    else:
        print("NO")