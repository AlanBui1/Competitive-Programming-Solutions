n, k = map(int, input().split())
k +=1 
ans =0

lis = []
for i in range(n):
    name = input()
    lis.append(len(name))

freq = [0 for i in range(26)]
for i in range(0,k):
    freq[lis[i]] += 1

for i in range(n):
    freq[lis[i]] -= 1
    ans += freq[lis[i]]
  
    if i+k < n:
        freq[lis[i+k]] += 1


print(ans)