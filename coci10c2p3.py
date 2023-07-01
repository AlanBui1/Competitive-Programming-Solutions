from queue import PriorityQueue

n = int(input())
word = input()

pq = PriorityQueue()
for i in range(n):
    pq.put((ord(word[i]), -i))

ans1 = ""
ans2 = ""
p2 = n-1

used = [0 for i in range(n)]

while not pq.empty():
    while p2 >= 0:
        if not used[p2]:
            break
        p2 -= 1

    if p2 >= 0:
        used[p2] = 1
        ans2 += word[p2]
    else:
        break

    while not pq.empty():
        let, ind = pq.get()
        let = chr(let)
        if used[-ind]:
            continue
        break
    used[-ind] = 1
    ans1 += let
    
    

if ans1 < ans2:
    print("DA")
else:
    print("NE")
print(ans1)