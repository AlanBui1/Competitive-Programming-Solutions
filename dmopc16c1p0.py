w = int(input())
c = int(input())

if w == 3 and c >= 95:
    m = "absolutely"
elif w == 1 and c <= 50:
    m = "fairly"
else:
    m = "very"
    
print("C.C. is " +m+ " satisfied with her pizza.")