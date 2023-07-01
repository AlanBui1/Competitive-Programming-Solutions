conv = {
    "D" : 1,
    "M" : 2,
    "O" : 3,
    "J" : 4
}

s = [conv[i] for i in input()]

longest = 1

for i in range(len(s)):
    leng = 1
    for k in range(i+1, len(s)):
        if s[k] <= s[k-1]:
            break
        leng += 1
        
    longest = max(longest, leng)

    
print(4-longest)