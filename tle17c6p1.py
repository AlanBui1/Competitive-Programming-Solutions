freq = [0 for i in range(26)]

n = int(input())
line = input()

for i in line:
    freq[ord(i)-97]+=1
    
if max(freq) > n/2 or n%2 == 1:
    print("No")
else:
    print("Yes")