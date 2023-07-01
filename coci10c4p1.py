import sys; input = sys.stdin.readline

cnt = 0
for i in range(5):
    word = input()
    if "FBI" in word:
        cnt += 1
        print(i+1, end = " ")
        
if not cnt:
    print("HE GOT AWAY!")