want = input()
has = input()

freq = [0 for i in range(26)]
need = 0

for i in want:
    freq[ord(i)-65] += 1
    need += 1
    
for i in has:
    if freq[ord(i)-65] > 0:
        freq[ord(i)-65] -= 1
        need -= 1
        
print(need)